# C语言 `<string.h>` 库详解

`<string.h>` 是C标准库中处理**字符串**和**内存块**的核心头文件。它提供两大类函数：

- **字符串函数**：以 `\0` 结尾的字符数组操作
- **内存函数**：任意字节块的操作

---

## 目录

- [一、字符串长度](#一字符串长度)
- [二、字符串复制](#二字符串复制)
- [三、字符串拼接](#三字符串拼接)
- [四、字符串比较](#四字符串比较)
- [五、字符串查找](#五字符串查找)
- [六、字符串分割](#六字符串分割)
- [七、错误信息](#七错误信息)
- [八、内存操作函数](#八内存操作函数)
- [九、安全使用要点](#九安全使用要点)
- [十、综合示例](#十综合示例)

---

## 一、字符串长度

### `strlen` — 计算字符串长度

```c
size_t strlen(const char *s);
```

- 从 `s` 开始计数，直到遇到 `\0`（不包含 `\0`）
- 返回 `size_t`（无符号整数）

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "hello";
    printf("%zu\n", strlen(str));  // 输出 5
    printf("%zu\n", sizeof(str));  // 输出 6（包含 '\0'）
    return 0;
}
```

> ⚠️ `strlen` 与 `sizeof` 的区别：`strlen` 运行时扫描到 `\0`，`sizeof` 编译时求数组总字节数。

---

## 二、字符串复制

### `strcpy` — 复制字符串

```c
char *strcpy(char *dest, const char *src);
```

- 将 `src`（含 `\0`）复制到 `dest`
- 返回 `dest`
- **不安全**：不检查 `dest` 空间是否足够，可能缓冲区溢出

```c
char dest[20];
strcpy(dest, "hello world");
printf("%s\n", dest);  // hello world
```

### `strncpy` — 按长度复制

```c
char *strncpy(char *dest, const char *src, size_t n);
```

- 最多复制 `n` 个字符
- 若 `src` 长度 < `n`，剩余位置补 `\0`
- 若 `src` 长度 ≥ `n`，**不会自动加 `\0`**！

```c
char buf[10];
strncpy(buf, "abcdefghij", 9);
buf[9] = '\0';  // 必须手动保证结尾
printf("%s\n", buf);  // abcdefghi
```

---

## 三、字符串拼接

### `strcat` — 拼接字符串

```c
char *strcat(char *dest, const char *src);
```

- 把 `src` 接到 `dest` 末尾（覆盖 `dest` 的 `\0`）
- 返回 `dest`
- **不安全**：不检查空间

```c
char dest[20] = "hello";
strcat(dest, " world");
printf("%s\n", dest);  // hello world
```

### `strncat` — 按长度拼接

```c
char *strncat(char *dest, const char *src, size_t n);
```

- 最多拼接 `n` 个字符，**自动加 `\0`**

```c
char dest[20] = "hello";
strncat(dest, " world!!!", 6);
printf("%s\n", dest);  // hello world
```

---

## 四、字符串比较

### `strcmp` — 比较字符串

```c
int strcmp(const char *s1, const char *s2);
```

- 逐字符按 **ASCII 值** 比较
- 返回值：
  - `< 0`：`s1 < s2`
  - `= 0`：`s1 == s2`
  - `> 0`：`s1 > s2`

```c
strcmp("abc", "abc");   // 0
strcmp("abc", "abd");   // < 0  ('c' < 'd')
strcmp("abc", "ABC");   // > 0  ('a'=97 > 'A'=65)
```

### `strncmp` — 按长度比较

```c
int strncmp(const char *s1, const char *s2, size_t n);
```

- 最多比较前 `n` 个字符

```c
strncmp("abcdef", "abcxyz", 3);  // 0（前3个相同）
```

> ⚠️ 不能用 `==` 比较字符串内容！`==` 比较的是指针地址。

---

## 五、字符串查找

### `strchr` — 正向查找字符

```c
char *strchr(const char *s, int c);
```

- 在 `s` 中从左找第一个 `c`
- 找到返回该位置指针，找不到返回 `NULL`

```c
char *p = strchr("hello", 'l');
printf("%s\n", p);  // llo
```

### `strrchr` — 反向查找字符

```c
char *strrchr(const char *s, int c);
```

- 从右往左找最后一个 `c`

```c
char *p = strrchr("hello", 'l');
printf("%s\n", p);  // lo
```

### `strstr` — 查找子串

```c
char *strstr(const char *haystack, const char *needle);
```

- 在 `haystack` 中找 `needle` 第一次出现的位置

```c
char *p = strstr("hello world", "world");
printf("%s\n", p);  // world
```

### `strpbrk` — 查找任一字符

```c
char *strpbrk(const char *s, const char *accept);
```

- 找 `s` 中第一个出现在 `accept` 里的字符

```c
char *p = strpbrk("hello", "aeiou");
printf("%s\n", p);  // ello（第一个元音是 'e'）
```

### `strspn` / `strcspn` — 计算匹配长度

```c
size_t strspn(const char *s, const char *accept);
size_t strcspn(const char *s, const char *reject);
```

- `strspn`：返回 `s` 开头连续属于 `accept` 的字符数
- `strcspn`：返回 `s` 开头连续**不属于** `reject` 的字符数

```c
strspn("12345abc", "0123456789");   // 5
strcspn("hello world", " ");        // 5（到空格前的长度）
```

---

## 六、字符串分割

### `strtok` — 分割字符串

```c
char *strtok(char *str, const char *delim);
```

- 首次调用传 `str`，后续调用传 `NULL`
- 用 `delim` 中的字符做分隔符，逐段返回
- **会修改原字符串**（把分隔符替换为 `\0`）
- **不可重入**（内部有静态变量），多线程不安全

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "apple,banana,orange";
    char *token = strtok(str, ",");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    return 0;
}
// 输出：
// apple
// banana
// orange
```

> 更安全的替代：`strtok_r`（POSIX，可重入版本）。

---

## 七、错误信息

### `strerror` — 错误码转字符串

```c
char *strerror(int errnum);
```

```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    printf("%s\n", strerror(2));  // No such file or directory
    printf("%s\n", strerror(EACCES));  // Permission denied
    return 0;
}
```

---

## 八、内存操作函数

这些函数不关心 `\0`，操作任意字节块。

### `memcpy` — 内存复制

```c
void *memcpy(void *dest, const void *src, size_t n);
```

- 复制 `n` 个字节
- **不保证**源和目标重叠时的正确性

```c
int src[5] = {1,2,3,4,5};
int dest[5];
memcpy(dest, src, sizeof(src));
```

### `memmove` — 安全内存复制（支持重叠）

```c
void *memmove(void *dest, const void *src, size_t n);
```

- 源和目标**可以重叠**，内部会选择正确方向复制

```c
char buf[] = "abcdef";
memmove(buf+2, buf, 4);  // 重叠也安全
printf("%s\n", buf);     // ababcd
```

### `memset` — 内存填充

```c
void *memset(void *s, int c, size_t n);
```

- 把 `s` 开始的 `n` 个字节设为 `c`
- 常用于清零数组

```c
int arr[10];
memset(arr, 0, sizeof(arr));      // 清零
memset(arr, -1, sizeof(arr));     // 全设为 -1（int 每字节 0xFF）
```

> ⚠️ `memset` 按**字节**填充，对 `int` 设非 0/-1 值会出错。

### `memcmp` — 内存比较

```c
int memcmp(const void *s1, const void *s2, size_t n);
```

- 逐字节比较 `n` 个字节

```c
int a[3] = {1,2,3}, b[3] = {1,2,4};
memcmp(a, b, sizeof(a));  // < 0
```

### `memchr` — 内存查找字符

```c
void *memchr(const void *s, int c, size_t n);
```

- 在 `n` 个字节内找第一个 `c`

```c
char *p = memchr("hello\0world", 'w', 11);
printf("%s\n", p);  // world（不受 \0 限制）
```

---

## 九、安全使用要点

| 风险函数 | 问题 | 安全替代 |
|---------|------|---------|
| `strcpy` | 不检查目标大小 | `strncpy` + 手动 `\0`，或 `snprintf` |
| `strcat` | 不检查目标大小 | `strncat` |
| `gets` | 无限读取（已从标准移除） | `fgets` |
| `sprintf` | 可能溢出 | `snprintf` |
| `strtok` | 修改原串、不可重入 | `strtok_r` 或手动解析 |

**通用原则**：

1. 始终确保目标缓冲区足够大
2. 使用带 `n` 的限制版本函数
3. 字符串必须以 `\0` 结尾
4. 注意 `strncpy` 不自动补 `\0` 的坑

---

## 十、综合示例

```c
#include <stdio.h>
#include <string.h>

int main() {
    char name[50] = "Zhang";
    char full[100];

    // 拼接
    strcat(name, " San");
    printf("姓名: %s\n", name);          // Zhang San
    printf("长度: %zu\n", strlen(name)); // 9

    // 复制 + 拼接
    strcpy(full, "Hello, ");
    strcat(full, name);
    strcat(full, "!");
    printf("%s\n", full);                // Hello, Zhang San!

    // 查找子串
    char *pos = strstr(full, "San");
    if (pos) printf("找到 'San' 在位置: %ld\n", pos - full);

    // 比较
    if (strcmp(name, "Zhang San") == 0)
        printf("姓名匹配\n");

    // 分割
    char copy[100];
    strcpy(copy, full);
    char *tok = strtok(copy, " ,!");
    while (tok) {
        printf("词: %s\n", tok);
        tok = strtok(NULL, " ,!");
    }

    return 0;
}
```

---

## 函数速查表

| 函数 | 功能 | 是否安全 |
|------|------|---------|
| `strlen` | 求字符串长度 | 安全 |
| `strcpy` | 复制字符串 | ⚠️ 溢出风险 |
| `strncpy` | 按长度复制 | 较安全（注意 `\0`） |
| `strcat` | 拼接字符串 | ⚠️ 溢出风险 |
| `strncat` | 按长度拼接 | 较安全 |
| `strcmp` | 比较字符串 | 安全 |
| `strncmp` | 按长度比较 | 安全 |
| `strchr` | 正向找字符 | 安全 |
| `strrchr` | 反向找字符 | 安全 |
| `strstr` | 找子串 | 安全 |
| `strpbrk` | 找任一字符 | 安全 |
| `strspn` | 计算匹配前缀长度 | 安全 |
| `strcspn` | 计算不匹配前缀长度 | 安全 |
| `strtok` | 分割字符串 | ⚠️ 修改原串、不可重入 |
| `strerror` | 错误码转字符串 | 安全 |
| `memcpy` | 内存复制 | ⚠️ 不支持重叠 |
| `memmove` | 内存复制（支持重叠） | 安全 |
| `memset` | 内存填充 | 安全（按字节） |
| `memcmp` | 内存比较 | 安全 |
| `memchr` | 内存查找字符 | 安全 |
