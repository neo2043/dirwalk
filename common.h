#define CHECK(cond, ...)                                                                                                                                       \
    do {                                                                                                                                                       \
        if (!(cond)) {                                                                                                                                         \
            fprintf(stderr, "%s:%d CHECK(%s) failed: ", __FILE__, __LINE__, #cond);                                                                            \
            fprintf(stderr, "" __VA_ARGS__);                                                                                                                   \
            fprintf(stderr, "\n");                                                                                                                             \
            exit(1);                                                                                                                                           \
        }                                                                                                                                                      \
    } while (0)
