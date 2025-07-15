#include "danya_string.h"

/**
 * @brief Преобразует строку в целое число.
 *
 * Обрабатывает пробельные символы в начале строки и знак числа.
 * В случае переполнения возвращает INT32_MAX или INT32_MIN в зависимости от
 * знака.
 *
 * @param[in] str Входная строка для преобразования.
 * @return Преобразованное целое число.
 */
int danya_atoi(const char *str) {
  int res = 0, sign = 1, overflow = 0;
  while (*str == ' ') {
    str++;
  }
  if (*str == '-') {
    str++;
    sign = -1;
  }
  if (*str == '+') {
    str++;
  }
  while (*str && *str >= '0' && *str <= '9' && !overflow) {
    res = res * 10 + (*str - '0');
    if (res < 0) overflow = 1;
    str++;
  }
  if (overflow)
    res = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    res *= sign;
  return res;
}

/**
 * @brief Перемещает блок памяти из одного места в другое.
 *
 * Использует временный буфер для безопасного перемещения данных.
 *
 * @param[out] dest Указатель на место назначения.
 * @param[in] src Указатель на исходные данные.
 * @param[in] n Количество байт для перемещения.
 * @return Указатель на место назначения.
 */
void *danya_memmove(void *dest, const void *src, danya_size_t n) {
  char *to = (char *)dest;
  char *from = (char *)src;
  char *tmp = (char *)malloc(sizeof(char) * n);

  if (tmp) {
    danya_memcpy(tmp, from, n);
    danya_memcpy(to, tmp, n);
    free(tmp);
  }

  return dest;
}

/**
 * @brief Добавляет строку `src` к концу строки `dest`.
 *
 * @param[in,out] dest Исходная строка, к которой будет добавлена `src`.
 * @param[in] src Строка для добавления.
 * @return Указатель на строку `dest` после добавления.
 */
char *danya_strcat(char *dest, const char *src) {
  int dest_len = danya_strlen(dest);
  int counter = 0;

  while (src[counter]) {
    dest[dest_len + counter] = src[counter];
    counter++;
  }

  dest[dest_len + counter] = '\0';

  return dest;
}

/**
 * @brief Сравнивает две строки.
 *
 * Возвращает отрицательное значение, если `str1` меньше `str2`, положительное
 * значение, если `str1` больше `str2`, и 0, если строки равны.
 *
 * @param[in] str1 Первая строка для сравнения.
 * @param[in] str2 Вторая строка для сравнения.
 * @return Результат сравнения.
 */
int danya_strcmp(const char *str1, const char *str2) {
  int result = 0;

  if (str1 && str2) {
    int counter = 0;
    while (str1[counter] && str2[counter] == str1[counter]) counter++;
    result = str1[counter] - str2[counter];
  }

  return result;
}

/**
 * @brief Копирует строку `src` в строку `dest`.
 *
 * @param[out] dest Место назначения для копирования.
 * @param[in] src Исходная строка для копирования.
 * @return Указатель на строку `dest` после копирования.
 */
char *danya_strcpy(char *dest, const char *src) {
  for (int counter = 0; src[counter]; counter++) dest[counter] = src[counter];
  dest[danya_strlen(src)] = '\0';
  return dest;
}

/**
 * @brief Возвращает количество символов в начале строки `str1`, которые также
 * находятся в строке `str2`.
 *
 * @param[in] str1 Исходная строка.
 * @param[in] str2 Строка символов для поиска.
 * @return Количество совпадающих символов.
 */
danya_size_t danya_strspn(const char *str1, const char *str2) {
  danya_size_t count = 0;
  while (*str1) {
    const char *temp = str2;
    int found = 0;
    while (*temp && !found) {
      if (*str1 == *temp) {
        found = 1;
      }
      temp++;
    }
    if (found) {
      count++;
      str1++;
    } else {
      str1 = "";
    }
  }
  return count;
}

/**
 * @brief Проверяет, является ли символ цифрой.
 *
 * @param[in] c Символ для проверки.
 * @return 1, если символ является цифрой; 0 в противном случае.
 */
int danya_isdigit(char c) { return (c >= '0' && c <= '9'); }

/**
 * @brief Преобразует строку в целое число с заданной основанием.
 *
 * Поддерживает основания от 2 до 36. Если основание равно 16 и строка
 * начинается с "0x" или "0X", эти префиксы игнорируются.
 *
 * @param[in] string Входная строка для преобразования.
 * @param[out] endptr Указатель на конец преобразованной части строки.
 * @param[in] basis Основание системы счисления.
 * @param[in] n_byte Количество байт для обработки.
 * @return Преобразованное целое число.
 */
unsigned long long int danya_strntollu(const char *string, char **endptr,
                                     int basis, int n_byte) {
  unsigned long long res = 0;
  short sign = 1;
  if (endptr) *endptr = danya_NULL;
  char dict[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  if (*string == '-') {
    sign = -1;
    string++;
  }
  if (basis == 16 &&
      (!danya_strncmp(string, "0x", 2) || !danya_strncmp(string, "0X", 2)))
    string += 2;
  long long val;
  short exit = 0;
  while (*string && n_byte && !exit) {
    char *tmp2;
    char current_sym =
        (*string >= 'a' && *string <= 'z') ? *string - 'a' + 'A' : *string;
    tmp2 = danya_strchr(dict, (int)current_sym);
    if (!tmp2)
      exit = 1;
    else {
      val = (tmp2 - dict) / sizeof(char);
      if (val >= basis)
        exit = 1;
      else {
        res = res * basis + val;
        string++;
        n_byte--;
      }
    }
    if (exit) *endptr = (char *)string;
  }
  return res * sign;
}

/**
 * @brief Преобразует всю строку в верхний регистр.
 *
 * @param[in,out] str Входная строка для преобразования.
 */
void danya_to_upper_string(char *str) {
  while (*str) {
    if (*str >= 'a' && *str <= 'z') *str = *str - 'a' + 'A';
    str++;
  }
}

/**
 * @brief Преобразует один символ в верхний регистр.
 *
 * @param[in] c Символ для преобразования.
 * @return Преобразованный символ в верхнем регистре.
 */
char danya_to_upper_single_char(char c) {
  char result = c;
  if (c >= 'a' && c <= 'z') {
    result = c - ('a' - 'A');
  }
  return result;
}

/**
 * @brief Преобразует один символ в нижний регистр.
 *
 * @param[in] c Символ для преобразования.
 * @return Преобразованный символ в нижнем регистре.
 */
char danya_to_lower_single_char(char c) {
  char result = c;
  if (c >= 'A' && c <= 'Z') {
    result = c + ('a' - 'A');
  }
  return result;
}

/**
 * @brief Обрезает строку слева, удаляя символы из `trim_chars`.
 *
 * @param[in,out] src Указатель на исходную строку, будет изменен на начало
 * обрезанной строки.
 * @param[in] trim_chars Строка символов для обрезки.
 * @param[in,out] src_len Длина исходной строки, будет изменена на длину
 * обрезанной строки.
 * @param[in] trim_chars_len Длина строки `trim_chars`.
 */
void danya_trim_left(const char **src, const char *trim_chars,
                   danya_size_t *src_len, const danya_size_t trim_chars_len) {
  danya_size_t counter = 0;
  while (src && counter != trim_chars_len) {
    if ((**src) == trim_chars[counter]) {
      (*src)++;
      (*src_len) -= 1;
      counter = 0;
    } else
      counter++;
  }
}

/**
 * @brief Обрезает строку справа, удаляя символы из `trim_chars`.
 *
 * @param[in,out] src Указатель на исходную строку, будет изменен на начало
 * обрезанной строки.
 * @param[in] trim_chars Строка символов для обрезки.
 * @param[in,out] src_len Длина исходной строки, будет изменена на длину
 * обрезанной строки.
 * @param[in] trim_chars_len Длина строки `trim_chars`.
 */
void danya_trim_right(const char **src, const char *trim_chars,
                    danya_size_t *src_len, const danya_size_t trim_chars_len) {
  danya_size_t counter = 0;
  danya_size_t i = (*src_len) - 1;
  while (src && counter != trim_chars_len) {
    if ((*src)[i] == trim_chars[counter]) {
      i--;
      (*src_len)--;
      counter = 0;
    } else
      counter++;
  }
}
