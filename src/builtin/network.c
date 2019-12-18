#include "escript.h"

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

static void * start_listen(void * _self, void * _contexts) {
    struct Function * self = _self;

    struct Stack * contexts = _contexts;
    struct Hash * context;
    struct ArrayValue * params;
    void * param;
    struct NumberValue * port_value;
    struct Function * function_value;
    struct ArrayValue * array_value;

    /*get params*/
    int i;
    params = NULL;
    for (i = contexts->size - 1; i >= 0; i--) {
        context = contexts->get(contexts, i);
        params = context->get(context, "params");
        if (params != NULL) {
            break;
        }
    }

    if (params != NULL) {
        param = params->values->get(params->values, 0);
        if (classOf(param) != NumberValue) {
            fputs("port is required", stderr);
            exit(-1);
        }
        port_value = param;
        param = params->values->get(params->values, 1);
        if (classOf(param) != Function) {
            fputs("listener function is required", stderr);
            exit(-1);
        }
        function_value = param;

        {
            int server_fd, new_socket;
            long read_count;
            struct sockaddr_in address;
            int address_len = sizeof (address);

            /*Creating socket file descriptor*/
            if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
                perror("In socket");
                exit(EXIT_FAILURE);
            }

            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons(port_value->value);

            memset(address.sin_zero, '\0', sizeof (address.sin_zero));

            if (bind(server_fd, (struct sockaddr *) &address, sizeof (address)) < 0) {
                perror("In bind");
                exit(EXIT_FAILURE);
            }
            if (listen(server_fd, 10) < 0) {
                perror("In listen");
                exit(EXIT_FAILURE);
            }
            printf("\nListening at port %d\n\n", port_value->value);
            while (1) {
                if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t*) & address_len)) < 0) {
                    perror("In accept");
                    exit(EXIT_FAILURE);
                }

                /*read request data*/
                int size = 0;
                int buffer_size = 1;
                char * request = calloc(sizeof (char), buffer_size + 1);
                char * buffer = calloc(sizeof (char), buffer_size + 1);
                char * tmp;
                while (1) {
                    read_count = read(new_socket, buffer, buffer_size);
                    if (read_count < 0) {
                        perror("In read");
                        exit(EXIT_FAILURE);
                    } else if (read_count == 0) {
                        break;
                    } else {
                        if (size + read_count > buffer_size) {
                            buffer_size *= 2;
                            tmp = request;
                            request = calloc(sizeof (char), buffer_size + 1);
                            memcpy(request, tmp, sizeof (char) * size);
                            free(tmp);
                            memcpy(request + size, buffer, read_count);
                            size += read_count;
                            buffer = calloc(sizeof (char), buffer_size + 1);
                            if (read_count < buffer_size / 2) {
                                break;
                            }
                        } else {
                            memcpy(request + size, buffer, read_count);
                            size += read_count;
                            if (read_count < buffer_size) {
                                break;
                            }
                        }
                    }
                }
                free(buffer);

                array_value = new(ArrayValue, new(Stack));
                array_value->values->append(array_value->values, new(StringValue, request));
                context = new(Hash);
                context->set(context, "params", array_value);
                contexts->append(contexts, context);

                struct SetValue * set_value = function_value->parent.run(function_value, contexts);
                contexts->pop(contexts);

                struct StringValue * string_value
                        = set_value->values->get(set_value->values, "result");
                char * response = string_value->value;

                if (write(new_socket, response, strlen(response)) != strlen(response)) {
                    fputs("can not write respond", stderr);
                    exit(-1);
                }
                close(new_socket);
            }
        }
    }

    return new(SetValue, new(Hash));
}

static void * init_listen() {
    struct Function * result = NULL;

    struct Set * tmp = new(Set, new(Stack));
    result = new(Function, tmp, tmp);

    result->parent.run = start_listen;

    return result;
}

void * init_network() {
    struct SetValue * result = NULL;

    struct Hash * hash = new(Hash);

    hash->set(hash, "listen", init_listen());

    result = new(SetValue, hash);

    return result;
}