#ifndef DANYA_STACK_H_
#define DANYA_STACK_H_

#include "danya_list.h"

namespace danya {
/**
 * @class stack
 * @brief Контейнер-адаптер, реализующий принцип "последний пришел - первый
 * вышел" (LIFO).
 * @tparam T Тип элементов, хранящихся в стеке.
 */
template <typename T>
class stack {
 public:
  /// @name Типы
  /// @{

  /**
   * @brief Определяет тип элемента, хранящегося в контейнере.
   * @details Соответствует типу T, который является параметром шаблона.
   */
  using value_type = T;
  /**
   * @brief Определяет тип ссылки на элемент.
   * @details Соответствует типу T&.
   */
  using reference = T&;
  /**
   * @brief Определяет тип константной ссылки на элемент.
   * @details Соответствует типу const T&.
   */
  using const_reference = const T&;
  /**
   * @brief Определяет тип для размера контейнера.
   * @details Стандартный тип - size_t.
   */
  using size_type = size_t;
  /// @}

 private:
  list<T> container_;

 public:
  /// @name Конструкторы
  /// @{

  /**
   * @brief Конструктор по умолчанию.
   * @details Создает пустой стек.
   */
  stack() : container_() {}
  /**
   * @brief Конструктор списка инициализации.
   * @details Создает стек, инициализированный с помощью
   * `std::initializer_list<T>`.
   * @param items Список инициализации, содержащий элементы для добавления в
   * стек.
   */
  stack(std::initializer_list<value_type> const& items) : container_(items) {}
  /**
   * @brief Конструктор копирования.
   * @details Создает копию стека `s`.
   * @param s Стек, который нужно скопировать.
   */
  stack(const stack& s) : container_(s.container_) {}
  /**
   * @brief Конструктор перемещения.
   * @details Создает стек, перемещая содержимое из `s`.
   * @param s Стек, из которого нужно переместить данные.
   */
  stack(stack&& s) noexcept : container_(std::move(s.container_)) {}
  /**
   * @brief Деструктор.
   * @details Уничтожает стек, освобождая все занятые ресурсы.
   */
  ~stack() = default;
  /**
   * @brief Оператор присваивания перемещением.
   * @details Присваивает содержимое стека `s` текущему стеку.
   * @param s Стек, из которого нужно переместить данные.
   * @return Ссылка на текущий стек.
   */
  stack& operator=(stack&& s) noexcept {
    container_ = std::move(s.container_);
    return *this;
  }
  /// @}

  /// @name Доступ к элементу стэка
  /// @{

  /**
   * @brief Доступ к верхнему элементу.
   * @details Возвращает константную ссылку на верхний элемент стека.
   * @return Константная ссылка на верхний элемент.
   */
  const_reference top() const { return container_.back(); }
  /// @}

  /// @name Проверка ёмкости
  /// @{

  /**
   * @brief Проверяет, пустой ли контейнер.
   * @details Возвращает `true`, если стек не содержит элементов.
   * @return `true`, если стек пуст, иначе `false`.
   */
  bool empty() const { return container_.empty(); }
  /**
   * @brief Возвращает количество элементов.
   * @details Возвращает количество элементов в стеке.
   * @return Количество элементов типа `size_type`.
   */
  size_type size() const { return container_.size(); }
  /// @}

  /// @name Модификаторы
  /// @{

  /**
   * @brief Добавляет элемент на вершину.
   * @details Вставляет новый элемент в стек.
   * @param value Константная ссылка на элемент для добавления.
   */
  void push(const_reference value) { container_.push_back(value); }
  /**
   * @brief Удаляет верхний элемент.
   * @details Удаляет элемент с вершины стека.
   */
  void pop() { container_.pop_back(); }
  /**
   * @brief Меняет содержимое стеков местами.
   * @details Обменивает содержимое текущего стека с содержимым стека `other`.
   * @param other Стек, с которым нужно поменяться содержимым.
   */
  void swap(stack& other) { container_.swap(other.container_); }

  /**
   * @brief Вставляет элементы в конец.
   * @details Вставляет новые элементы в конец контейнера.
   * @tparam Args Типы аргументов.
   * @param args Аргументы для добавления.
   */
  template <typename... Args>
  void insert_many_back(Args&&... args) {
    container_.insert_many_back(std::forward<Args>(args)...);
  }
  /// @}
};
}  // namespace danya

#endif
