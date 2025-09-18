#ifndef DANYA_VECTOR_H_
#define DANYA_VECTOR_H_

#include <algorithm>
#include <initializer_list>
#include <limits>
#include <stdexcept>
#include <utility>

namespace danya {
template <typename T>
class vector {
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
   * @brief Определяет тип константной ссылки.
   */
  using const_reference = const T &;
  /**
   * @brief Определяет тип итератора для прохода по контейнеру.
   */
  using iterator = T *;
  /**
   * @brief Определяет константный тип итератора для прохода по контейнеру.
   */
  using const_iterator = const T *;
  /**
   * @brief Определяет тип для размера контейнера.
   */
  using size_type = size_t;

 private:
  value_type *data_;
  size_type size_;
  size_type capacity_;

 public:
  /**
   * @brief Конструктор по умолчанию. Создает пустой вектор.
   */
  vector() : data_(nullptr), size_(0), capacity_(0) {}

  /**
   * @brief Параметризованный конструктор. Создает вектор заданного размера.
   * @param n Размер вектора.
   */
  explicit vector(size_type n)
      : data_(n ? new T[n]() : nullptr), size_(n), capacity_(n) {}

  /**
   * @brief Конструктор со списком инициализации. Создает вектор,
   * инициализированный списком.
   * @param items Список элементов для инициализации.
   */
  vector(std::initializer_list<value_type> const &items)
      : data_(new T[items.size()]),
        size_(items.size()),
        capacity_(items.size()) {
    std::copy(items.begin(), items.end(), data_);
  }

  /**
   * @brief Конструктор копирования.
   * @param v Вектор, который нужно скопировать.
   */
  vector(const vector &v)
      : data_(new T[v.capacity_]), size_(v.size_), capacity_(v.capacity_) {
    std::copy(v.data_, v.data_ + v.size_, data_);
  }

  /**
   * @brief Конструктор перемещения.
   * @param v Вектор, который нужно переместить.
   */
  vector(vector &&v) noexcept
      : data_(v.data_), size_(v.size_), capacity_(v.capacity_) {
    v.data_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  }

  /**
   * @brief Деструктор.
   */
  ~vector() { delete[] data_; }

  /**
   * @brief Перегрузка оператора присваивания для перемещения объекта.
   * @param v Вектор, который нужно переместить.
   * @return Ссылка на текущий объект.
   */
  vector &operator=(vector &&v) noexcept {
    if (this != &v) {
      delete[] data_;
      data_ = v.data_;
      size_ = v.size_;
      capacity_ = v.capacity_;
      v.data_ = nullptr;
      v.size_ = 0;
      v.capacity_ = 0;
    }
    return *this;
  }

  /**
   * @brief Доступ к указанному элементу с проверкой границ.
   * @param pos Позиция элемента.
   * @return Ссылка на элемент.
   * @throw std::out_of_range Если позиция выходит за границы.
   */
  reference at(size_type pos) {
    if (pos >= size_ || size_ == 0) throw std::out_of_range("vector::at");
    return data_[pos];
  }

  /**
   * @brief Доступ к указанному элементу.
   * @param pos Позиция элемента.
   * @return Ссылка на элемент.
   */
  reference operator[](size_type pos) { return data_[pos]; }
  /**
   * @brief Доступ к указанному элементу.
   * @param pos Позиция элемента.
   * @return Константная ссылка на элемент.
   */
  const_reference operator[](size_type pos) const { return data_[pos]; }
  /**
   * @brief Доступ к первому элементу.
   * @return Константная ссылка на первый элемент.
   * @throw std::out_of_range Если контейнер пуст.
   */
  const_reference front() const {
    if (empty()) throw std::out_of_range("vector::front on empty vector");
    return data_[0];
  }
  /**
   * @brief Доступ к последнему элементу.
   * @return Константная ссылка на последний элемент.
   * @throw std::out_of_range Если контейнер пуст.
   */
  const_reference back() const {
    if (empty()) throw std::out_of_range("vector::back on empty vector");
    return data_[size_ - 1];
  }
  /**
   * @brief Прямой доступ к базовому массиву.
   * @return Указатель на первый элемент.
   */
  T *data() { return data_; }

  /**
   * @brief Возвращает итератор на начало.
   * @return Итератор на начало.
   */
  iterator begin() { return data_; }
  /**
   * @brief Возвращает итератор на конец.
   * @return Итератор на конец.
   */
  iterator end() { return data_ + size_; }
  /**
   * @brief Возвращает константный итератор на начало.
   * @return Константный итератор на начало.
   */
  const_iterator cbegin() const { return data_; }

  /**
   * @brief Проверяет, пустой ли контейнер.
   * @return true, если пустой; false в противном случае.
   */
  bool empty() const { return size_ == 0; }
  /**
   * @brief Возвращает количество элементов.
   * @return Количество элементов.
   */
  size_type size() const { return size_; }
  /**
   * @brief Возвращает максимально возможное количество элементов.
   * @return Максимальное количество элементов.
   */
  size_type max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  }

  /**
   * @brief Выделяет место для заданного количества элементов.
   * @param newCapacity Новый размер буфера.
   */
  void reserve(size_type newCapacity) {
    if (newCapacity > capacity_) {
      T *new_data = new T[newCapacity];
      std::copy(data_, data_ + size_, new_data);
      delete[] data_;
      data_ = new_data;
      capacity_ = newCapacity;
    }
  }

  /**
   * @brief Возвращает количество элементов, которое можно хранить в текущем
   * выделенном хранилище.
   * @return Размер буфера.
   */
  size_type capacity() const { return capacity_; }

  /**
   * @brief Уменьшает использование памяти, освобождая неиспользуемую.
   */
  void shrink_to_fit() {
    if (size_ < capacity_) {
      T *new_data = new T[size_];
      std::copy(data_, data_ + size_, new_data);
      delete[] data_;
      data_ = new_data;
      capacity_ = size_;
    }
  }

  /**
   * @brief Очищает содержимое контейнера.
   */
  void clear() { size_ = 0; }

  /**
   * @brief Вставляет элемент в указанную позицию и возвращает итератор,
   * указывающий на новый элемент.
   * @param pos Итератор, указывающий на позицию вставки.
   * @param value Значение для вставки.
   * @return Итератор, указывающий на вставленный элемент.
   */
  iterator insert(iterator pos, const_reference value) {
    size_type index = pos - begin();
    if (size_ == capacity_) {
      reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    pos = begin() + index;
    std::move_backward(pos, end(), end() + 1);
    *pos = value;
    size_++;
    return pos;
  }

  /**
   * @brief Удаляет элемент в указанной позиции.
   * @param pos Итератор, указывающий на позицию удаления.
   */
  void erase(iterator pos) {
    if (pos >= end()) return;
    std::move(pos + 1, end(), pos);
    size_--;
  }

  /**
   * @brief Добавляет элемент в конец.
   * @param value Значение для добавления.
   */
  void push_back(const_reference value) {
    if (size_ == capacity_) {
      reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data_[size_++] = value;
  }

  /**
   * @brief Удаляет последний элемент.
   */
  void pop_back() {
    if (size_ > 0) {
      size_--;
    }
  }

  /**
   * @brief Обменивает содержимое с другим вектором.
   * @param other Вектор для обмена содержимым.
   */
  void swap(vector &other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }

  /**
   * @brief Вставляет несколько элементов в указанную позицию.
   * @tparam Args Типы вставляемых элементов.
   * @param pos Константный итератор, указывающий на позицию вставки.
   * @param args Элементы для вставки.
   * @return Итератор, указывающий на первый из вставленных элементов.
   */
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    auto index = pos - cbegin();
    size_type count = sizeof...(Args);

    if (size_ + count > capacity_) {
      reserve(std::max(capacity_ * 2, size_ + count));
    }

    iterator insert_pos = begin() + index;

    std::move_backward(insert_pos, end(), end() + count);

    size_type i = 0;
    (void)std::initializer_list<int>{
        (*(insert_pos + i++) = std::forward<Args>(args), 0)...};

    size_ += count;
    return insert_pos;
  }

  /**
   * @brief Вставляет несколько элементов в конец вектора.
   * @tparam Args Типы вставляемых элементов.
   * @param args Элементы для вставки.
   */
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push_back(std::forward<Args>(args)), ...);
  }
};
}  // namespace danya
#endif
