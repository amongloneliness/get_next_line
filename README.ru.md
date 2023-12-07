***
## Описание
Кастомные функции для чтения строк из файловых дескрипторов.
Вы можете использовать их для чтения данных из файлов в своих c проектах.

## Использование:

### Необходимое ПО

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Инструкция

**1. Запустите make из проекта**

**2. Перенесите файлы "libline.a" и "get_next_line.h" в папку своего проекта**

**3. Для исполльзования функции в своем коде, подключите заголовочный файл:**

```c
#include "get_next_line.h"
```

**4. Скомпилируйте ваш c файл с полученной библиотекой и запустите его:**

```shell
gcc -Wall -Werror -Wextra <your_project.c> libline.a && ./a.out
```

### Полный список поддерживаемых инструкций утилиты make:
> **make**  
> **make all**  
> **make re**  
> **make clean**  
> **make fclean**
