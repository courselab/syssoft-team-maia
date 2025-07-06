#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int verify_password(const char *key)
{
    return strcmp(key, "foo") == 0;
}

int main(void)
{
    char user_key[10];

    printf("Enter password: ");
    if (!fgets(user_key, sizeof(user_key), stdin))
        return 1;
    user_key[strcspn(user_key, "\n")] = '\0';

    if (!verify_password(user_key))
    {
        printf("Access denied\n");
        exit(1);
    }

    printf("Access granted.\n");
    return 0;
}