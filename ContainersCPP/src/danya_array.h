#ifndef DANYA_ARRAY_H_
#define DANYA_ARRAY_H_

#include <algorithm>
#include <initializer_list>
#include <stdexcept>

namespace danya {

/**
 * @class array
 * @brief Контейнер, инкапсулирующий статический массив.
 * @details Сочетает свойства статического массива с преимуществами контейнерных
 * классов STL, такими как итераторы и хранение размера.
 * @tparam T Тип элементов, хранящихся в контейнере.
 * @tparam N Размер массива.
 */
template <typename T, std::size_t N>
class array {
 public:
  /** @typedef value_type
   * @brief Определяет тип элемента.
   */
  using value_type = T;
  /** @typedef reference
   * @brief Определяет тип ссылки на элемент.
   */
  using reference = T &;
  /** @typedef const_reference
   * @brief Определяет тип константной ссылки на элемент.
   */
  using const_reference = const T &;
  /** @typedef iterator
   * @brief Определяет тип для итерации по контейнеру.
   */
  using iterator = T *;
  /** @typedef const_iterator
   * @brief Определяет константный тип для итерации по контейнеру.
   */
  using const_iterator = const T *;
  /** @typedef size_type
   * @brief Определяет тип для размера контейнера.
   */
  using size_type = size_t;

 private:
  T data_[N];

 public:
  /**
   * @brief Конструктор по умолчанию.
   * @details Создает пустой массив.
   */
  array() = default;

  /**
   * @brief Конструктор со списком инициализации.
   * @details Создает массив, инициализированный с помощью
   * `std::initializer_list<T>`.
   * @param items Список инициализации.
   * @throw `std::out_of_range` Если количество инициализаторов превышает размер
   * массива.
   */
  array(std::initializer_list<value_type> const &items) {
    if (items.size() > N) {
      throw std::out_of_range("Too many initializers");
    }
    std::copy(items.begin(), items.end(), data_);
  }

  /**
   * @brief Конструктор копирования.
   * @details Создает новый массив, копируя содержимое другого.
   * @param a Копируемый массив.
   */
  array(const array &a) { std::copy(a.data_, a.data_ + N, data_); }

  /**
   * @brief Конструктор перемещения.
   * @details Перемещает содержимое из другого массива.
   * @param a Перемещаемый массив.
   */
  array(array &&a) noexcept { std::copy(a.data_, a.data_ + N, data_); }

  /**
   * @brief Деструктор.
   */
  ~array() = default;

  /**
   * @brief Оператор присваивания перемещением.
   * @details Перегрузка оператора присваивания для перемещения объекта.
   * @param a Перемещаемый объект.
   * @return Ссылка на текущий объект.
   */
  array &operator=(array &&a) noexcept {
    if (this != &a) {
      std::copy(a.data_, a.data_ + N, data_);
    }
    return *this;
  }

  /**
   * @brief Доступ к элементу с проверкой границ.
   * @details Возвращает ссылку на элемент с указанной позицией, проверяя, что
   * позиция находится в допустимых пределах.
   * @param pos Позиция элемента.
   * @return Ссылка на элемент.
   * @throw `std::out_of_range` Если позиция выходит за границы массива.
   */
  reference at(size_type pos) {
    if (pos >= N) {
      throw std::out_of_range("array::at");
    }
    return data_[pos];
  }

  /**
   * @brief Доступ к элементу без проверки границ.
   * @details Возвращает ссылку на элемент с указанной позицией.
   * @param pos Позиция элемента.
   * @return Ссылка на элемент.
   */
  reference operator[](size_type pos) { return data_[pos]; }

  /**
   * @brief Доступ к первому элементу.
   * @details Возвращает константную ссылку на первый элемент в контейнере.
   * @return Константная ссылка на первый элемент.
   */
  const_reference front() const { return data_[0]; }

  /**
   * @brief Доступ к последнему элементу.
   * @details Возвращает константную ссылку на последний элемент в контейнере.
   * @return Константная ссылка на последний элемент.
   */
  const_reference back() const { return data_[N - 1]; }

  /**
   * @brief Прямой доступ к базовому массиву.
   * @details Возвращает указатель на базовый массив, что обеспечивает прямой
   * доступ к данным.
   * @return Итератор, указывающий на начало массива.
   */
  iterator data() { return data_; }

  /**
   * @brief Возвращает итератор на начало.
   * @details Возвращает итератор, указывающий на первый элемент в контейнере.
   * @return Итератор на начало.
   */
  iterator begin() { return data_; }

  /**
   * @brief Возвращает итератор на конец.
   * @details Возвращает итератор, указывающий на элемент, следующий за
   * последним.
   * @return Итератор на конец.
   */
  iterator end() { return data_ + N; }

  /**
   * @brief Проверяет, пустой ли контейнер.
   * @details Возвращает `true`, если контейнер пуст, и `false` в противном
   * случае.
   * @return Логическое значение, указывающее, пуст ли контейнер.
   */
  bool empty() const { return N == 0; }

  /**
   * @brief Возвращает количество элементов.
   * @details Возвращает количество элементов, хранящихся в контейнере.
   * @return Количество элементов.
   */
  size_type size() const { return N; }

  /**
   * @brief Возвращает максимально возможное количество элементов.
   * @details Возвращает максимальное количество элементов, которое может
   * содержать контейнер.
   * @return Максимально возможное количество элементов.
   */
  size_type max_size() const { return N; }

  /**
   * @brief Обменивает содержимое.
   * @details Обменивает содержимое контейнера с содержимым другого.
   * @param other Другой массив, с которым нужно обменяться.
   */
  void swap(array &other) {
    for (size_type i = 0; i < N; ++i) {
      std::swap(data_[i], other.data_[i]);
    }
  }

  /**
   * @brief Заполняет контейнер.
   * @details Присваивает всем элементам в контейнере указанное значение.
   * @param value Значение, которым нужно заполнить контейнер.
   */
  void fill(const_reference value) { std::fill(begin(), end(), value); }
};
}  // namespace danya

#endif
