# Printf

C implementation of printf from scratch. A project at Ecole 42.

### Build

```C
make
gcc -I ./includes/ft_printf.h /path/to/C/file/*.c -lftprintf -L .
```

### Usage

Function Declaration :
```C
int     ft_printf(char *string, ...)
```
Examples
```C
#include "ft_printf.h"

int     main(int ac, char **av)
{
    ft_printf("%d", 45);
}
```
