#include "danya_string.h"

/**
 * @brief Ищет символ `c` в первых `n` байтах памяти, начиная с `str`.
 *
 * @param[in] str Указатель на начало области памяти.
 * @param[in] c Символ для поиска.
 * @param[in] n Количество байт для поиска.
 * @return Указатель на найденный символ или danya_NULL, если символ не найден.
 */
void *danya_memchr(const void *str, int c, danya_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  void *out = danya_NULL;
  int stop_flag = 0;
  danya_size_t i = 0;
  while (i < n && ptr && !stop_flag) {
    if (*ptr == (unsigned char)c) {
      out = ptr;
      stop_flag = 1;
    } else {
      ptr++;
      i++;
    }
  }
  return out;
}

/**
 * @brief Сравнивает первые `n` байт двух областей памяти.
 *
 * @param[in] str1 Первая область памяти для сравнения.
 * @param[in] str2 Вторая область памяти для сравнения.
 * @param[in] n Количество байт для сравнения.
 * @return Отрицательное значение, если `str1` меньше `str2`, положительное
 * значение, если `str1` больше `str2`, и 0, если области памяти равны.
 */
int danya_memcmp(const void *str1, const void *str2, danya_size_t n) {
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  int dif = 0;
  int stop_flag = 0;
  danya_size_t i = 0;
  while (i < n && !stop_flag) {
    dif = *s1 - *s2;
    if (*s1 != *s2)
      stop_flag = 1;
    else {
      s1++;
      s2++;
      i++;
    }
  }
  return dif;
}

/**
 * @brief Копирует `n` байт из области памяти `src` в область памяти `dest`.
 *
 * @param[out] dest Место назначения для копирования.
 * @param[in] src Исходная область памяти для копирования.
 * @param[in] n Количество байт для копирования.
 * @return Указатель на место назначения.
 */
void *danya_memcpy(void *dest, const void *src, danya_size_t n) {
  unsigned char *destination = (unsigned char *)dest;
  unsigned char *source = (unsigned char *)src;
  danya_size_t i = 0;
  while (i < n) {
    destination[i] = source[i];
    i++;
  }
  return dest;
}

/**
 * @brief Устанавливает `n` байт в области памяти `str` в значение `c`.
 *
 * @param[in,out] str Область памяти для установки.
 * @param[in] c Значение для установки.
 * @param[in] n Количество байт для установки.
 * @return Указатель на область памяти после установки.
 */
void *danya_memset(void *str, int c, danya_size_t n) {
  char *str_tmp = str;
  for (danya_size_t i = 0; i < n; i++) {
    str_tmp[i] = c;
  }
  return str_tmp;
}

/**
 * @brief Ищет символ `c` в строке `str`.
 *
 * @param[in] str Исходная строка для поиска.
 * @param[in] c Символ для поиска.
 * @return Указатель на найденный символ или danya_NULL, если символ не найден.
 * Если `c` равен '\0', возвращает указатель на конец строки.
 */
char *danya_strchr(const char *str, int c) {
  char ch = (char)c;
  char *result = danya_NULL;
  danya_size_t flag = 0;
  danya_size_t counter = 0;

  while (str[counter] != '\0' && !flag) {
    if (str[counter] == ch) {
      result = ((char *)str) + counter;
      flag = 1;
    }
    counter++;
  }

  if (ch == '\0') {
    result = ((char *)str) + counter;
  }

  return result;
}

/**
 * @brief Добавляет не более `n` символов из строки `src` к концу строки `dest`.
 *
 * @param[in,out] dest Исходная строка, к которой будет добавлена `src`.
 * @param[in] src Строка для добавления.
 * @param[in] n Максимальное количество символов для добавления.
 * @return Указатель на строку `dest` после добавления.
 */
char *danya_strncat(char *dest, const char *src, danya_size_t n) {
  danya_size_t length_of_dest = danya_strlen(dest);
  danya_size_t counter = 0;

  while (counter < n && src[counter]) {
    dest[length_of_dest + counter] = src[counter];
    counter++;
  }
  dest[length_of_dest + counter] = '\0';

  return dest;
}

/**
 * @brief Сравнивает первые `n` символов двух строк.
 *
 * @param[in] str1 Первая строка для сравнения.
 * @param[in] str2 Вторая строка для сравнения.
 * @param[in] n Количество символов для сравнения.
 * @return Отрицательное значение, если `str1` меньше `str2`, положительное
 * значение, если `str1` больше `str2`, и 0, если строки равны.
 */
int danya_strncmp(const char *str1, const char *str2, danya_size_t n) {
  int result = 0;
  danya_size_t counter = 0;
  int flag = 0;

  while (n > 0 && counter < n && !flag) {
    if (str1[counter] == '\0' || str1[counter] != str2[counter]) {
      result = str1[counter] - str2[counter];
      flag = 1;
    }
    counter++;
  }
  return result;
}

/**
 * @brief Копирует не более `n` символов из строки `src` в строку `dest`.
 *
 * Если длина `src` меньше `n`, оставшиеся символы в `dest` заполняются символом
 * '\0'.
 *
 * @param[out] dest Место назначения для копирования.
 * @param[in] src Исходная строка для копирования.
 * @param[in] n Максимальное количество символов для копирования.
 * @return Указатель на строку `dest` после копирования.
 */
char *danya_strncpy(char *dest, const char *src, danya_size_t n) {
  danya_size_t counter = 0;

  while (counter < n) {
    if (src[counter]) {
      dest[counter] = src[counter];
    } else {
      dest[counter] = '\0';
    }
    counter++;
  }
  return dest;
}

/**
 * @brief Возвращает количество символов в начале строки `str1`, которые не
 * находятся в строке `str2`.
 *
 * @param[in] str1 Исходная строка.
 * @param[in] str2 Строка символов для поиска.
 * @return Количество символов, не совпадающих с `str2`.
 */
danya_size_t danya_strcspn(const char *str1, const char *str2) {
  danya_size_t len = 0;
  int flag = 0;
  danya_size_t j;

  for (danya_size_t i = 0; (flag == 0) && (str1[i] != '\0'); i++) {
    for (j = 0; ((str2[j] != str1[i]) && (str2[j] != '\0')); j++);
    str2[j] == str1[i] ? flag = 1 : len++;
  }

  return len;
}

/**
 * @brief Возвращает строку, описывающую ошибку с кодом `errnum`.
 *
 * Если код ошибки не найден, возвращает строку "Unknown error: <код>" на
 * некоторых платформах или "No error information" на других.
 *
 * @param[in] errnum Код ошибки.
 * @return Строка, описывающая ошибку.
 */
char *danya_strerror(int errnum) {
  static char err[danya_ERR_LENGTH] = "";

  if (errnum >= 0 && errnum < danya_ERR_LIST_SIZE) {
    const char *err_list[] = danya_ERR_LIST;
    danya_strncpy(err, err_list[errnum], danya_strlen(err_list[errnum]) + 1);
  } else {
#if defined __MACH__ || defined __APPLE__
    danya_sprintf(err, "Unknown error: %d", errnum);
#elif defined __linux__
    danya_sprintf(err, "No error information");
#endif
  }
  return err;
}

/**
 * @brief Возвращает длину строки.
 *
 * @param[in] str Входная строка.
 * @return Количество символов в строке до символа '\0'.
 */
danya_size_t danya_strlen(const char *str) {
  danya_size_t count = 0;
  while (*str != '\0') {
    count++;
    str++;
  }
  return count;
}

/**
 * @brief Ищет первый символ из строки `str2` в строке `str1`.
 *
 * @param[in] str1 Исходная строка для поиска.
 * @param[in] str2 Строка символов для поиска.
 * @return Указатель на первый найденный символ или danya_NULL, если символ не
 * найден.
 */
char *danya_strpbrk(const char *str1, const char *str2) {
  char *result = danya_NULL;
  int stop_flag = 0;

  while (*str1 != '\0' && !stop_flag) {
    const char *temp = str2;
    while (*temp != '\0' && !stop_flag) {
      if (*str1 == *temp) {
        result = (char *)str1;
        stop_flag = 1;
      } else
        temp++;
    }
    if (!stop_flag) str1++;
  }
  return result;
}

/**
 * @brief Ищет последнее вхождение символа `c` в строке `str`.
 *
 * Если `c` равен '\0', возвращает указатель на конец строки.
 *
 * @param[in] str Исходная строка для поиска.
 * @param[in] c Символ для поиска.
 * @return Указатель на последнее вхождение символа или danya_NULL, если символ не
 * найден.
 */
char *danya_strrchr(const char *str, int c) {
  const char *last_enter = danya_NULL;

  while (*str != '\0') {
    if (*str == (char)c) {
      last_enter = str;
    }
    str++;
  }

  if (c == '\0') {
    last_enter = (char *)str;
  }

  return (char *)last_enter;
}

/**
 * @brief Ищет подстроку `needle` в строке `haystack`.
 *
 * @param[in] haystack Исходная строка для поиска.
 * @param[in] needle Подстрока для поиска.
 * @return Указатель на начало найденной подстроки или danya_NULL, если подстрока
 * не найдена.
 */
char *danya_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }

  while (*haystack) {
    const char *h = haystack;
    const char *n = needle;

    while (*h && *n && (*h == *n)) {
      h++;
      n++;
    }

    if (*n == '\0') {
      return (char *)haystack;
    }

    haystack++;
  }

  return danya_NULL;
}

/**
 * @brief Разделяет строку на токены по разделителям из строки `delim`.
 *
 * Каждый вызов функции возвращает следующий токен из предыдущей строки.
 *
 * @param[in,out] str Исходная строка для разбиения или danya_NULL для продолжения
 * разбиения предыдущей строки.
 * @param[in] delim Строка разделителей.
 * @return Указатель на следующий токен или danya_NULL, если токены закончились.
 */
char *danya_strtok(char *str, const char *delim) {
  static char *last = danya_NULL;
  if (str != danya_NULL) {
    last = str;
  }

  if (last == danya_NULL) {
    return danya_NULL;
  }

  char *token_start = last;
  while (*token_start && danya_strchr(delim, *token_start)) {
    token_start++;
  }

  if (*token_start == '\0') {
    last = danya_NULL;
    return danya_NULL;
  }

  char *token_end = token_start;
  while (*token_end && !danya_strchr(delim, *token_end)) {
    token_end++;
  }

  if (*token_end) {
    *token_end = '\0';
    last = token_end + 1;
  } else {
    last = danya_NULL;
  }

  return token_start;
}
