#ifndef DANYA_MAP_H_
#define DANYA_MAP_H_

#include <cstddef>
#include <stdexcept>
#include <utility>

#include "rbtree/rbtree.h"
#include "danya_vector.h"

namespace danya {
/**
 * @brief Класс ассоциативного контейнера, хранящего пары "ключ-значение".
 *
 * @details Map (словарь) - это ассоциативный контейнер, который хранит пары
 * "ключ-значение", отсортированные по ключу в порядке возрастания. Реализован
 * на основе красно-черного дерева (RBTree) для быстрого поиска, вставки и
 * удаления элементов. Каждый ключ в контейнере уникален.
 *
 * @tparam Key Тип ключа.
 * @tparam T Тип значения.
 * @tparam Compare Компаратор для сравнения ключей.
 */
template <typename Key, typename T, typename Compare = std::less<Key>>
class map {
 private:
  /**
   * @brief Внутренняя структура-компаратор для сравнения пар "ключ-значение" по
   * ключу.
   */
  struct key_compare_impl {
    Compare comp_;
    key_compare_impl() : comp_() {}
    explicit key_compare_impl(const Compare& comp) : comp_(comp) {}

    bool operator()(const std::pair<const Key, T>& lhs,
                    const std::pair<const Key, T>& rhs) const {
      return comp_(lhs.first, rhs.first);
    }
  };

  RBTree<std::pair<const Key, T>, key_compare_impl> tree_;

 public:
  using key_type = Key;  /**< @brief Тип ключа. */
  using mapped_type = T; /**< @brief Тип значения. */
  using value_type =
      std::pair<const key_type,
                mapped_type>; /**< @brief Тип пары "ключ-значение". */
  using reference = value_type&; /**< @brief Тип ссылки на элемент. */
  using const_reference =
      const value_type&; /**< @brief Тип константной ссылки на элемент. */
  using iterator = typename RBTree<value_type, key_compare_impl>::
      iterator; /**< @brief Тип итератора для перебора элементов. */
  using const_iterator = typename RBTree<value_type, key_compare_impl>::
      const_iterator; /**< @brief Тип константного итератора. */
  using size_type = std::size_t; /**< @brief Тип для размера контейнера. */

  /**
   * @brief Конструктор по умолчанию.
   * @details Создает пустой map.
   */
  explicit map() : tree_(key_compare_impl()) {}

  /**
   * @brief Конструктор со списком инициализации.
   * @details Создает map, инициализированный списком элементов.
   * @param items Список инициализации элементов.
   */
  explicit map(std::initializer_list<value_type> const& items);

  /**
   * @brief Конструктор копирования.
   * @details Создает map, копируя содержимое другого.
   * @param m Копируемый map.
   */
  explicit map(const map& m);

  /**
   * @brief Конструктор перемещения.
   * @details Создает map, перемещая содержимое другого.
   * @param m Перемещаемый map.
   */
  explicit map(map&& m) noexcept;

  /**
   * @brief Деструктор.
   */
  ~map() = default;

  /**
   * @brief Оператор присваивания копированием.
   * @param m Присваиваемый map.
   * @return Ссылка на текущий объект.
   */
  map& operator=(const map& m);

  /**
   * @brief Оператор присваивания перемещением.
   * @param m Присваиваемый map.
   * @return Ссылка на текущий объект.
   */
  map& operator=(map&& m) noexcept;

  /**
   * @brief Возвращает итератор на первый элемент.
   * @return Итератор, указывающий на начало контейнера.
   */
  iterator begin();

  /**
   * @brief Возвращает итератор, следующий за последним элементом.
   * @return Итератор, указывающий на конец контейнера.
   */
  iterator end();

  /**
   * @brief Возвращает константный итератор на первый элемент (const-версия).
   * @return Константный итератор, указывающий на начало контейнера.
   */
  const_iterator begin() const;

  /**
   * @brief Возвращает константный итератор, следующий за последним элементом
   * (const-версия).
   * @return Константный итератор, указывающий на конец контейнера.
   */
  const_iterator end() const;

  /**
   * @brief Возвращает константный итератор на первый элемент.
   * @return Константный итератор, указывающий на начало контейнера.
   */
  const_iterator cbegin() const;

  /**
   * @brief Возвращает константный итератор, следующий за последним элементом.
   * @return Константный итератор, указывающий на конец контейнера.
   */
  const_iterator cend() const;

  /**
   * @brief Проверяет, пуст ли контейнер.
   * @return `true`, если контейнер пуст, иначе `false`.
   */
  bool empty() const;

  /**
   * @brief Возвращает количество элементов в контейнере.
   * @return Количество элементов.
   */
  size_type size() const;

  /**
   * @brief Возвращает максимально возможное количество элементов.
   * @return Максимальный размер контейнера.
   */
  size_type max_size() const;

  /**
   * @brief Доступ к элементу по ключу с проверкой границ.
   * @param key Ключ искомого элемента.
   * @return Ссылка на значение, соответствующее ключу.
   * @throws std::out_of_range Если ключ не найден.
   */
  mapped_type& at(const key_type& key);

  /**
   * @brief Доступ к элементу по ключу с проверкой границ (const-версия).
   * @param key Ключ искомого элемента.
   * @return Константная ссылка на значение, соответствующее ключу.
   * @throws std::out_of_range Если ключ не найден.
   */
  const mapped_type& at(const key_type& key) const;

  /**
   * @brief Доступ или вставка элемента по ключу.
   * @details Если ключ существует, возвращает ссылку на соответствующее
   * значение. Если нет, вставляет новый элемент с ключом и возвращает ссылку на
   * новое, инициализированное по умолчанию значение.
   * @param key Ключ искомого элемента.
   * @return Ссылка на значение, соответствующее ключу.
   */
  mapped_type& operator[](const key_type& key);

  /**
   * @brief Вставляет новый элемент в контейнер.
   * @details Если элемент с таким ключом уже есть, вставка не происходит.
   * @param value Пара "ключ-значение" для вставки.
   * @return Пару: итератор, указывающий на вставленный элемент (или на
   * существующий, если вставка не произошла), и `bool`, который равен `true`,
   * если вставка произошла, и `false` в противном случае.
   */
  std::pair<iterator, bool> insert(const value_type& value);

  /**
   * @brief Вставляет новый элемент, используя ключ и значение.
   * @param key Ключ.
   * @param obj Значение.
   * @return Пару: итератор, указывающий на вставленный элемент, и `bool`,
   * который равен `true`, если вставка произошла, и `false` в противном случае.
   */
  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);

  /**
   * @brief Вставляет элемент, если его нет, или присваивает новое значение,
   * если ключ уже существует.
   * @param key Ключ.
   * @param obj Новое значение.
   * @return Пару: итератор, указывающий на вставленный/измененный элемент, и
   * `bool`, который равен `true`, если произошла вставка, и `false`, если
   * присваивание.
   */
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj);

  /**
   * @brief Удаляет элемент по итератору.
   * @param pos Итератор, указывающий на удаляемый элемент.
   */
  void erase(iterator pos);

  /**
   * @brief Очищает содержимое контейнера.
   */
  void clear();

  /**
   * @brief Обменивает содержимое с другим map.
   * @param other map, с которым происходит обмен.
   */
  void swap(map& other);

  /**
   * @brief Переносит элементы из другого map в текущий.
   * @details Если ключ уже существует, элемент не переносится.
   * @param other map, из которого переносятся элементы.
   */
  void merge(map& other);

  /**
   * @brief Проверяет наличие элемента с заданным ключом.
   * @param key Ключ для поиска.
   * @return `true`, если элемент найден, иначе `false`.
   */
  bool contains(const key_type& key) const;

  /**
   * @brief Вставляет несколько элементов с помощью variadic templates.
   * @tparam Args Типы вставляемых аргументов.
   * @param args Аргументы, которые будут вставлены.
   * @return Вектор пар, где каждая пара содержит итератор и `bool` результат
   * вставки.
   */
  template <typename... Args>
  danya::vector<std::pair<iterator, bool>> insert_many(Args&&... args);
};

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map(std::initializer_list<value_type> const& items) {
  for (const auto& item : items) {
    insert(item);
  }
}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map(const map& m) : tree_(m.tree_) {}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map(map&& m) noexcept : tree_(std::move(m.tree_)) {}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>& map<Key, T, Compare>::operator=(const map& m) {
  if (this != &m) {
    tree_ = m.tree_;
  }
  return *this;
}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>& map<Key, T, Compare>::operator=(map&& m) noexcept {
  if (this != &m) {
    tree_ = std::move(m.tree_);
  }
  return *this;
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::iterator map<Key, T, Compare>::begin() {
  return tree_.begin();
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::iterator map<Key, T, Compare>::end() {
  return tree_.end();
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::begin()
    const {
  return tree_.begin();
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::end()
    const {
  return tree_.end();
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::cbegin()
    const {
  return tree_.cbegin();
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::cend()
    const {
  return tree_.cend();
}

template <typename Key, typename T, typename Compare>
bool map<Key, T, Compare>::empty() const {
  return tree_.size() == 0;
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::size_type map<Key, T, Compare>::size() const {
  return tree_.size();
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::size_type map<Key, T, Compare>::max_size()
    const {
  return tree_.max_size();
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::mapped_type& map<Key, T, Compare>::at(
    const key_type& key) {
  value_type search_pair{key, mapped_type{}};
  Node<std::pair<const Key, T>>* node = tree_.find(search_pair);
  if (!node) {
    throw std::out_of_range("Key not found");
  }
  return node->val_.second;
}

template <typename Key, typename T, typename Compare>
const typename map<Key, T, Compare>::mapped_type& map<Key, T, Compare>::at(
    const key_type& key) const {
  value_type search_pair{key, mapped_type{}};
  Node<std::pair<const Key, T>>* node = tree_.find(search_pair);
  if (!node) {
    throw std::out_of_range("Key not found");
  }
  return node->val_.second;
}

template <typename Key, typename T, typename Compare>
typename map<Key, T, Compare>::mapped_type& map<Key, T, Compare>::operator[](
    const key_type& key) {
  value_type search_pair{key, mapped_type{}};
  Node<std::pair<const Key, T>>* node = tree_.find(search_pair);
  typename map<Key, T, Compare>::mapped_type* result = nullptr;

  if (node) {
    result = &(node->val_.second);
  } else {
    auto insert_result = tree_.insert(search_pair);
    result = &(insert_result.first->second);
  }

  return *result;
}

template <typename Key, typename T, typename Compare>
std::pair<typename map<Key, T, Compare>::iterator, bool>
map<Key, T, Compare>::insert(const value_type& value) {
  return tree_.insert(value);
}

template <typename Key, typename T, typename Compare>
std::pair<typename map<Key, T, Compare>::iterator, bool>
map<Key, T, Compare>::insert(const key_type& key, const mapped_type& obj) {
  return insert(value_type{key, obj});
}

template <typename Key, typename T, typename Compare>
std::pair<typename map<Key, T, Compare>::iterator, bool>
map<Key, T, Compare>::insert_or_assign(const key_type& key,
                                       const mapped_type& obj) {
  value_type search_pair{key, mapped_type{}};
  Node<std::pair<const Key, T>>* node = tree_.find(search_pair);
  std::pair<typename map<Key, T, Compare>::iterator, bool> result;

  if (node) {
    node->val_.second = obj;
    result = {iterator(node), false};
  } else {
    result = insert(value_type{key, obj});
  }

  return result;
}

template <typename Key, typename T, typename Compare>
void map<Key, T, Compare>::erase(iterator pos) {
  tree_.erase(*pos);
}

template <typename Key, typename T, typename Compare>
void map<Key, T, Compare>::clear() {
  tree_.clear();
}

template <typename Key, typename T, typename Compare>
void map<Key, T, Compare>::swap(map& other) {
  tree_.swap(other.tree_);
}

template <typename Key, typename T, typename Compare>
void map<Key, T, Compare>::merge(map& other) {
  for (auto it = other.begin(); it != other.end();) {
    auto current_it = it++;
    if (insert(*current_it).second) {
      other.erase(current_it);
    }
  }
}

template <typename Key, typename T, typename Compare>
bool map<Key, T, Compare>::contains(const key_type& key) const {
  value_type search_pair{key, mapped_type{}};
  return tree_.contains(search_pair);
}

template <typename Key, typename T, typename Compare>
template <typename... Args>
danya::vector<std::pair<typename map<Key, T, Compare>::iterator, bool>>
map<Key, T, Compare>::insert_many(Args&&... args) {
  danya::vector<std::pair<iterator, bool>> results;
  (results.push_back(insert(args)), ...);
  return results;
}

}  // namespace danya
#endif
