#ifndef DANYA_QUEUE_H_
#define DANYA_QUEUE_H_

#include "danya_list.h"

namespace danya {
/**
 * @brief Класс для контейнера "очередь" (queue).
 * @details Этот контейнер организован по принципу FIFO (First-In, First-Out),
 * что означает, что первый добавленный элемент будет удален первым.
 * Элементы добавляются в конец очереди и удаляются из начала.
 * @tparam T Тип элементов, хранимых в очереди.
 */
template <typename T>
class queue {
 public:
  /**
   * @brief Определяет тип элемента.
   */
  using value_type = T;
  /**
   * @brief Определяет тип ссылки на элемент.
   */
  using reference = T &;
  /**
   * @brief Определяет тип константной ссылки на элемент.
   */
  using const_reference = const T &;
  /**
   * @brief Определяет тип размера контейнера.
   */
  using size_type = size_t;

 private:
  danya::list<T> container_;

 public:
  /**
   * @brief Конструктор по умолчанию.
   * @details Создает пустую очередь.
   */
  queue() : container_() {}
  /**
   * @brief Конструктор, инициализирующий список.
   * @details Создает очередь, инициализированную с помощью
   * std::initializer_list<T>.
   * @param items Список инициализации.
   */
  queue(std::initializer_list<value_type> const &items) : container_(items) {}
  /**
   * @brief Конструктор копирования.
   * @details Создает копию существующей очереди.
   * @param q Очередь, которую нужно скопировать.
   */
  queue(const queue &q) : container_(q.container_) {}
  /**
   * @brief Конструктор перемещения.
   * @details Перемещает содержимое из другой очереди в эту.
   * @param q Очередь, из которой нужно переместить содержимое.
   */
  queue(queue &&q) noexcept : container_(std::move(q.container_)) {}
  /**
   * @brief Деструктор.
   */
  ~queue() = default;
  /**
   * @brief Перегруженный оператор присваивания перемещением.
   * @details Перемещает объект.
   * @param q Очередь, из которой нужно переместить содержимое.
   * @return Ссылка на эту очередь.
   */
  queue &operator=(queue &&q) noexcept {
    container_ = std::move(q.container_);
    return *this;
  }

  /**
   * @brief Доступ к первому элементу.
   * @return Константная ссылка на первый элемент.
   */
  const_reference front() const { return container_.front(); }
  /**
   * @brief Доступ к последнему элементу.
   * @return Константная ссылка на последний элемент.
   */
  const_reference back() const { return container_.back(); }

  /**
   * @brief Проверяет, пустой ли контейнер.
   * @return `true`, если контейнер пуст, иначе `false`.
   */
  bool empty() const { return container_.empty(); }
  /**
   * @brief Возвращает количество элементов.
   * @return Количество элементов в контейнере.
   */
  size_type size() const { return container_.size(); }

  /**
   * @brief Добавляет элемент в конец очереди.
   * @param value Значение элемента для добавления.
   */
  void push(const_reference value) { container_.push_back(value); }
  /**
   * @brief Удаляет первый элемент из очереди.
   */
  void pop() { container_.pop_front(); }
  /**
   * @brief Меняет содержимое двух очередей.
   * @param other Очередь, с которой нужно поменяться содержимым.
   */
  void swap(queue &other) { container_.swap(other.container_); }

  /**
   * @brief Вставляет несколько элементов в конец очереди.
   * @tparam Args Типы аргументов.
   * @param args Аргументы, которые нужно вставить.
   */
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    container_.insert_many_back(std::forward<Args>(args)...);
  }
};
}  // namespace danya

#endif
