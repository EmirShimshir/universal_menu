#include <stdio.h>
#include "headers/menu.h"
#include "args.h"

void foo()
{
    printf("foo");
}

void foo_w_data(void *data)
{
    UNPACK_STRUCT(foo_w_data, data);

    printf("%d\n", args->a);
    printf("%d\n", args->b);
    printf("%d\n", args->c);
}

void foobuzz()
{
    printf("foozbuzz");
}

void func()
{
    printf("Hello menu");
}

int main()
{
    MENU menu = create_menu();

    add_command(menu, func, "func");
    add_command(menu, foo, "foo_func");
    add_command_with_data(menu, foo_w_data, "wdata", foo_w_data_pack(1, 2, 3));

    MENU sub_menu = create_menu();
    add_command(sub_menu, foobuzz, "foobuzz");
    add_sub_menu(menu, sub_menu, "foo_menu");

    execute_menu(menu);

    free_menu(menu);

    return 0;
}
