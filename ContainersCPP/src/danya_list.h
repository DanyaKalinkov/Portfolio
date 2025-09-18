#ifndef DANYA_LIST_H_
#define DANYA_LIST_H_

#include <cstddef>
#include <initializer_list>
#include <limits>
#include <utility>

namespace danya {

/**
 * @class list
 * @brief Класс-контейнер, реализующий двусвязный список.
 *
 * List - это последовательный контейнер, который хранит элементы в виде
 * узлов, связанных указателями. Он позволяет эффективно добавлять и
 * удалять элементы в любой части списка.
 *
 * @tparam T Тип элементов, хранимых в списке.
 */
template <typename T>
class list {
 private:
  /**
   * @struct Node
   * @brief Структура узла списка.
   *
   * Каждый узел содержит значение, указатель на следующий элемент (next)
   * и указатель на предыдущий элемент (prev).
   */
  struct Node {
    T value;
    Node* next;
    Node* prev;

    Node() : next(nullptr), prev(nullptr) {}
    explicit Node(const T& val) : value(val), next(nullptr), prev(nullptr) {}
    explicit Node(T&& val)
        : value(std::move(val)), next(nullptr), prev(nullptr) {}
  };

 public:
  /**
   * @typedef value_type
   * @brief Тип элементов, хранимых в контейнере.
   */
  using value_type = T;
  /**
   * @typedef reference
   * @brief Тип ссылки на элемент.
   */
  using reference = T&;
  /**
   * @typedef const_reference
   * @brief Тип константной ссылки на элемент.
   */
  using const_reference = const T&;
  /**
   * @typedef size_type
   * @brief Беззнаковый целочисленный тип для представления размера контейнера.
   */
  using size_type = size_t;

  class ListIterator;
  class ListConstIterator;

  /**
   * @typedef iterator
   * @brief Тип для итерации по элементам контейнера.
   */
  using iterator = ListIterator;
  /**
   * @typedef const_iterator
   * @brief Константный тип для итерации по элементам контейнера.
   */
  using const_iterator = ListConstIterator;

  /**
   * @class ListIterator
   * @brief Класс-итератор для danya::list.
   *
   * Предоставляет доступ к элементам и возможность перемещаться по списку.
   */
  class ListIterator {
   public:
    ListIterator() : node_(nullptr) {}
    explicit ListIterator(Node* node) : node_(node) {}

    /**
     * @brief Оператор разыменования.
     * @return Ссылка на значение текущего узла.
     */
    reference operator*() const { return node_->value; }
    /**
     * @brief Префиксный оператор инкремента.
     * @return Ссылка на итератор, указывающий на следующий элемент.
     */
    ListIterator& operator++() {
      if (node_) node_ = node_->next;
      return *this;
    }
    /**
     * @brief Префиксный оператор декремента.
     * @return Ссылка на итератор, указывающий на предыдущий элемент.
     */
    ListIterator& operator--() {
      if (node_) node_ = node_->prev;
      return *this;
    }
    /**
     * @brief Оператор сравнения на равенство.
     * @param other Другой итератор.
     * @return true, если итераторы указывают на один и тот же узел.
     */
    bool operator==(const ListIterator& other) const {
      return node_ == other.node_;
    }
    /**
     * @brief Оператор сравнения на неравенство.
     * @param other Другой итератор.
     * @return true, если итераторы указывают на разные узлы.
     */
    bool operator!=(const ListIterator& other) const {
      return node_ != other.node_;
    }

   private:
    Node* node_;
    friend class list<T>;
  };

  /**
   * @class ListConstIterator
   * @brief Константный класс-итератор для danya::list.
   *
   * Предоставляет доступ к элементам только для чтения.
   */
  class ListConstIterator {
   public:
    ListConstIterator() : node_(nullptr) {}
    explicit ListConstIterator(const Node* node) : node_(node) {}
    ListConstIterator(const ListIterator& it) : node_(it.node_) {}

    /**
     * @brief Оператор разыменования.
     * @return Константная ссылка на значение текущего узла.
     */
    const_reference operator*() const { return node_->value; }
    /**
     * @brief Префиксный оператор инкремента.
     * @return Ссылка на итератор, указывающий на следующий элемент.
     */
    ListConstIterator& operator++() {
      if (node_) node_ = node_->next;
      return *this;
    }
    /**
     * @brief Префиксный оператор декремента.
     * @return Ссылка на итератор, указывающий на предыдущий элемент.
     */
    ListConstIterator& operator--() {
      if (node_) node_ = node_->prev;
      return *this;
    }
    /**
     * @brief Оператор сравнения на равенство.
     * @param other Другой константный итератор.
     * @return true, если итераторы указывают на один и тот же узел.
     */
    bool operator==(const ListConstIterator& other) const {
      return node_ == other.node_;
    }
    /**
     * @brief Оператор сравнения на неравенство.
     * @param other Другой константный итератор.
     * @return true, если итераторы указывают на разные узлы.
     */
    bool operator!=(const ListConstIterator& other) const {
      return node_ != other.node_;
    }

   private:
    const Node* node_;
    friend class list<T>;
  };

  /**
   * @brief Конструктор по умолчанию. Создает пустой список.
   */
  list() : size_(0) {
    dummy_ = new Node();
    dummy_->next = dummy_;
    dummy_->prev = dummy_;
  }

  /**
   * @brief Параметризованный конструктор. Создает список размера n.
   * @param n Количество элементов.
   */
  explicit list(size_type n) : list() {
    for (size_type i = 0; i < n; ++i) {
      push_back(T());
    }
  }

  /**
   * @brief Конструктор списка инициализации.
   * Создает список, инициализированный с помощью std::initializer_list<T>.
   * @param items Список инициализации.
   */
  list(std::initializer_list<value_type> const& items) : list() {
    for (const auto& item : items) {
      push_back(item);
    }
  }

  /**
   * @brief Конструктор копирования.
   * @param l Список, который будет скопирован.
   */
  list(const list& l) : list() {
    Node* current = l.dummy_->next;
    while (current != l.dummy_) {
      push_back(current->value);
      current = current->next;
    }
  }

  /**
   * @brief Конструктор перемещения.
   * @param l Список, который будет перемещен.
   */
  list(list&& l) noexcept : dummy_(l.dummy_), size_(l.size_) {
    l.dummy_ = new Node();
    l.dummy_->next = l.dummy_;
    l.dummy_->prev = l.dummy_;
    l.size_ = 0;
  }

  /**
   * @brief Деструктор.
   * Очищает содержимое списка и освобождает память.
   */
  ~list() {
    clear();
    delete dummy_;
  }

  /**
   * @brief Оператор присваивания перемещения.
   * @param l Список, который будет перемещен.
   * @return Ссылка на текущий объект.
   */
  list& operator=(list&& l) noexcept {
    if (this != &l) {
      clear();
      delete dummy_;
      dummy_ = l.dummy_;
      size_ = l.size_;
      l.dummy_ = new Node();
      l.dummy_->next = l.dummy_;
      l.dummy_->prev = l.dummy_;
      l.size_ = 0;
    }
    return *this;
  }

  /**
   * @brief Доступ к первому элементу.
   * @return Константная ссылка на первый элемент.
   */
  const_reference front() const { return dummy_->next->value; }
  /**
   * @brief Доступ к последнему элементу.
   * @return Константная ссылка на последний элемент.
   */
  const_reference back() const { return dummy_->prev->value; }

  /**
   * @brief Возвращает итератор на начало списка.
   * @return Итератор, указывающий на первый элемент.
   */
  iterator begin() { return iterator(dummy_->next); }
  /**
   * @brief Возвращает итератор на конец списка.
   * @return Итератор, указывающий на фиктивный узел (за "последним" элементом).
   */
  iterator end() { return iterator(dummy_); }

  /**
   * @brief Проверяет, является ли контейнер пустым.
   * @return true, если контейнер пуст.
   */
  bool empty() const { return size_ == 0; }
  /**
   * @brief Возвращает количество элементов в контейнере.
   * @return Количество элементов.
   */
  size_type size() const { return size_; }
  /**
   * @brief Возвращает максимально возможное количество элементов.
   * @return Максимально возможное количество элементов.
   */
  size_type max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(Node);
  }

  /**
   * @brief Очищает содержимое контейнера.
   */
  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  /**
   * @brief Вставляет элемент в указанную позицию.
   * @param pos Итератор, указывающий, куда вставить элемент.
   * @param value Значение для вставки.
   * @return Итератор, указывающий на новый элемент.
   */
  iterator insert(iterator pos, const_reference value) {
    Node* new_node = new Node(value);
    Node* pos_node = pos.node_;
    Node* prev_node = pos_node->prev;

    new_node->next = pos_node;
    new_node->prev = prev_node;
    prev_node->next = new_node;
    pos_node->prev = new_node;

    ++size_;
    return iterator(new_node);
  }

  /**
   * @brief Удаляет элемент в указанной позиции.
   * @param pos Итератор, указывающий на элемент, который нужно удалить.
   */
  void erase(iterator pos) {
    if (pos.node_ == dummy_ || empty()) {
      return;
    }

    Node* node_to_delete = pos.node_;
    Node* prev_node = node_to_delete->prev;
    Node* next_node = node_to_delete->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;

    delete node_to_delete;
    --size_;
  }

  /**
   * @brief Добавляет элемент в конец.
   * @param value Значение для добавления.
   */
  void push_back(const_reference value) { insert(end(), value); }
  /**
   * @brief Удаляет последний элемент.
   */
  void pop_back() {
    if (!empty()) {
      erase(iterator(dummy_->prev));
    }
  }
  /**
   * @brief Добавляет элемент в начало.
   * @param value Значение для добавления.
   */
  void push_front(const_reference value) { insert(begin(), value); }
  /**
   * @brief Удаляет первый элемент.
   */
  void pop_front() {
    if (!empty()) {
      erase(begin());
    }
  }

  /**
   * @brief Обменивает содержимое с другим списком.
   * @param other Другой список.
   */
  void swap(list& other) {
    std::swap(dummy_, other.dummy_);
    std::swap(size_, other.size_);
  }

  /**
   * @brief Сливает два отсортированных списка.
   * @param other Другой отсортированный список.
   */
  void merge(list& other) {
    if (this == &other || other.empty()) return;

    iterator this_it = begin();
    while (this_it.node_ != dummy_ && !other.empty()) {
      if (other.front() < *this_it) {
        Node* node_to_move = other.dummy_->next;

        other.dummy_->next = node_to_move->next;
        node_to_move->next->prev = other.dummy_;
        --other.size_;

        Node* this_node = this_it.node_;
        Node* prev_node = this_node->prev;

        prev_node->next = node_to_move;
        node_to_move->prev = prev_node;
        node_to_move->next = this_node;
        this_node->prev = node_to_move;
        ++size_;
      } else {
        ++this_it;
      }
    }

    if (!other.empty()) {
      splice(end(), other);
    }
  }

  /**
   * @brief Перемещает элементы из другого списка в текущий.
   * @param pos Позиция, куда вставить элементы.
   * @param other Список, из которого перемещаются элементы.
   */
  void splice(const_iterator pos, list& other) {
    if (other.empty()) return;

    Node* pos_node = const_cast<Node*>(pos.node_);
    Node* first = other.dummy_->next;
    Node* last = other.dummy_->prev;
    Node* prev_node = pos_node->prev;

    prev_node->next = first;
    first->prev = prev_node;
    last->next = pos_node;
    pos_node->prev = last;

    size_ += other.size_;

    other.dummy_->next = other.dummy_;
    other.dummy_->prev = other.dummy_;
    other.size_ = 0;
  }

  /**
   * @brief Изменяет порядок элементов на обратный.
   */
  void reverse() {
    if (size_ <= 1) return;
    Node* current = dummy_;
    do {
      std::swap(current->next, current->prev);
      current = current->prev;
    } while (current != dummy_);
  }

  /**
   * @brief Удаляет подряд идущие дублирующиеся элементы.
   */
  void unique() {
    if (size_ <= 1) return;
    iterator it = begin();
    iterator next = it;
    ++next;
    while (next != end()) {
      if (*it == *next) {
        iterator to_erase = next;
        ++next;
        erase(to_erase);
      } else {
        it = next;
        ++next;
      }
    }
  }

  /**
   * @brief Сортирует элементы списка.
   */
  void sort() {
    if (size_ <= 1) return;
    bool swapped;
    do {
      swapped = false;
      for (iterator it = begin(); it != end(); ++it) {
        iterator next = it;
        ++next;
        if (next != end() && *next < *it) {
          std::swap(*it, *next);
          swapped = true;
        }
      }
    } while (swapped);
  }

  /**
   * @brief Вставляет несколько элементов в указанную позицию.
   * @tparam Args Типы вставляемых аргументов.
   * @param pos Итератор, указывающий, куда вставить элементы.
   * @param args Значения для вставки.
   * @return Итератор, указывающий на первый из вставленных элементов.
   */
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args) {
    iterator non_const_pos(const_cast<Node*>(pos.node_));

    (insert(non_const_pos, value_type(std::forward<Args>(args))), ...);

    return iterator(const_cast<Node*>(pos.node_));
  }

  /**
   * @brief Вставляет несколько элементов в конец списка.
   * @tparam Args Типы вставляемых аргументов.
   * @param args Значения для вставки.
   */
  template <typename... Args>
  void insert_many_back(Args&&... args) {
    (push_back(std::forward<Args>(args)), ...);
  }

  /**
   * @brief Вставляет несколько элементов в начало списка.
   * @tparam Args Типы вставляемых аргументов.
   * @param args Значения для вставки.
   */
  template <typename... Args>
  void insert_many_front(Args&&... args) {
    value_type temp_args[] = {std::forward<Args>(args)...};

    for (size_t i = sizeof...(Args); i > 0; --i) {
      push_front(temp_args[i - 1]);
    }
  }

 private:
  Node* dummy_;
  size_type size_;
};

}  // namespace danya

#endif
