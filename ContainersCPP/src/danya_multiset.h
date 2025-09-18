#ifndef DANYA_MULTISET_H_
#define DANYA_MULTISET_H_

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>

#include "rbtree/rbtree.h"
#include "danya_vector.h"

namespace danya {
/**
 * @brief Ассоциативный контейнер, повторяющий логику множества, но позволяющий
 * хранить идентичные элементы.
 * @tparam Key Тип ключа (Key).
 * @tparam Compare Компаратор для сортировки элементов.
 */
template <typename Key, typename Compare = std::less<Key>>
class multiset {
 private:
  struct key_compare_impl {
    Compare comp_;
    key_compare_impl() : comp_() {}
    explicit key_compare_impl(const Compare& comp) : comp_(comp) {}

    bool operator()(const Key& lhs, const Key& rhs) const {
      return comp_(lhs, rhs);
    }
  };

  RBTree<Key, key_compare_impl> tree_;

 public:
  // Member types
  /**
   * @brief Определяет тип элемента (Key).
   */
  using key_type = Key;
  /**
   * @brief Тип значения (значение само является ключом).
   */
  using value_type = Key;
  /**
   * @brief Определяет тип ссылки на элемент.
   */
  using reference = value_type&;
  /**
   * @brief Определяет тип константной ссылки на элемент.
   */
  using const_reference = const value_type&;
  /**
   * @brief Определяет тип для итерации по контейнеру.
   */
  using iterator = typename RBTree<value_type, key_compare_impl>::iterator;
  /**
   * @brief Определяет константный тип для итерации по контейнеру.
   */
  using const_iterator =
      typename RBTree<value_type, key_compare_impl>::const_iterator;
  /**
   * @brief Определяет тип размера контейнера.
   */
  using size_type = std::size_t;
  /**
   * @brief Тип компаратора для ключей.
   */
  using key_compare = Compare;

  // Member functions
  /**
   * @brief Конструктор по умолчанию, создает пустой контейнер.
   */
  explicit multiset() : tree_(key_compare_impl()) {}

  /**
   * @brief Конструктор списка инициализации, создает контейнер,
   * инициализированный с помощью std::initializer_list<T>.
   * @param items Список инициализации.
   */
  explicit multiset(std::initializer_list<value_type> const& items);
  /**
   * @brief Конструктор копирования.
   * @param ms Контейнер для копирования.
   */
  explicit multiset(const multiset& ms);
  /**
   * @brief Конструктор перемещения.
   * @param ms Контейнер для перемещения.
   */
  explicit multiset(multiset&& ms) noexcept;
  /**
   * @brief Деструктор.
   */
  ~multiset() = default;

  /**
   * @brief Перегрузка оператора присваивания для копирования.
   * @param ms Контейнер для копирования.
   * @return Ссылка на текущий объект.
   */
  multiset& operator=(const multiset& ms);
  /**
   * @brief Перегрузка оператора присваивания для перемещения.
   * @param ms Контейнер для перемещения.
   * @return Ссылка на текущий объект.
   */
  multiset& operator=(multiset&& ms) noexcept;

  // Iterators
  /**
   * @brief Возвращает итератор на начало.
   * @return Итератор на начало контейнера.
   */
  iterator begin();
  /**
   * @brief Возвращает итератор на конец.
   * @return Итератор на конец контейнера.
   */
  iterator end();
  /**
   * @brief Возвращает константный итератор на начало.
   * @return Константный итератор на начало контейнера.
   */
  const_iterator begin() const;
  /**
   * @brief Возвращает константный итератор на конец.
   * @return Константный итератор на конец контейнера.
   */
  const_iterator end() const;
  /**
   * @brief Возвращает константный итератор на начало.
   * @return Константный итератор на начало контейнера.
   */
  const_iterator cbegin() const;
  /**
   * @brief Возвращает константный итератор на конец.
   * @return Константный итератор на конец контейнера.
   */
  const_iterator cend() const;

  // Capacity
  /**
   * @brief Проверяет, пуст ли контейнер.
   * @return true, если контейнер пуст, иначе false.
   */
  bool empty() const;
  /**
   * @brief Возвращает количество элементов.
   * @return Количество элементов в контейнере.
   */
  size_type size() const;
  /**
   * @brief Возвращает максимально возможное количество элементов.
   * @return Максимальный размер контейнера.
   */
  size_type max_size() const;

  // Modifiers
  /**
   * @brief Вставляет узел и возвращает итератор на место, где находится элемент
   * в контейнере.
   * @param value Значение для вставки.
   * @return Итератор на вставленный элемент.
   */
  iterator insert(const value_type& value);
  /**
   * @brief Удаляет элемент по позиции.
   * @param pos Позиция элемента для удаления.
   */
  void erase(iterator pos);
  /**
   * @brief Очищает содержимое.
   */
  void clear();
  /**
   * @brief Меняет содержимое с другим контейнером.
   * @param other Контейнер, с которым нужно поменяться.
   */
  void swap(multiset& other);
  /**
   * @brief Перемещает узлы из другого контейнера в текущий.
   * @param other Контейнер, из которого нужно переместить узлы.
   */
  void merge(multiset& other);

  // Lookup
  /**
   * @brief Находит элемент с указанным ключом.
   * @param key Ключ для поиска.
   * @return Итератор на найденный элемент.
   */
  iterator find(const key_type& key);
  /**
   * @brief Находит элемент с указанным ключом (const версия).
   * @param key Ключ для поиска.
   * @return Константный итератор на найденный элемент.
   */
  const_iterator find(const key_type& key) const;
  /**
   * @brief Проверяет, содержит ли контейнер элемент с указанным ключом.
   * @param key Ключ для проверки.
   * @return true, если элемент найден, иначе false.
   */
  bool contains(const key_type& key) const;
  /**
   * @brief Возвращает количество элементов, соответствующих определенному
   * ключу.
   * @param key Ключ для подсчета.
   * @return Количество элементов, равных ключу.
   */
  size_type count(const key_type& key) const;

  /**
   * @brief Возвращает итератор на первый элемент, который не меньше заданного
   * ключа.
   * @param key Ключ для поиска.
   * @return Итератор на первый элемент, который не меньше ключа.
   */
  iterator lower_bound(const key_type& key);
  /**
   * @brief Возвращает константный итератор на первый элемент, который не меньше
   * заданного ключа (const версия).
   * @param key Ключ для поиска.
   * @return Константный итератор на первый элемент, который не меньше ключа.
   */
  const_iterator lower_bound(const key_type& key) const;
  /**
   * @brief Возвращает итератор на первый элемент, который больше заданного
   * ключа.
   * @param key Ключ для поиска.
   * @return Итератор на первый элемент, который больше ключа.
   */
  iterator upper_bound(const key_type& key);
  /**
   * @brief Возвращает константный итератор на первый элемент, который больше
   * заданного ключа (const версия).
   * @param key Ключ для поиска.
   * @return Константный итератор на первый элемент, который больше ключа.
   */
  const_iterator upper_bound(const key_type& key) const;
  /**
   * @brief Возвращает диапазон элементов, соответствующих определенному ключу.
   * @param key Ключ для поиска диапазона.
   * @return Пара итераторов, определяющая диапазон.
   */
  std::pair<iterator, iterator> equal_range(const key_type& key);

  /**
   * @brief Вставляет несколько элементов за один вызов.
   * @tparam Args Типы вставляемых аргументов.
   * @param args Аргументы, которые будут вставлены.
   * @return Вектор итераторов на вставленные элементы.
   */
  template <typename... Args>
  danya::vector<iterator> insert_many(Args&&... args);
};

template <typename Key, typename Compare>
multiset<Key, Compare>::multiset(std::initializer_list<value_type> const& items)
    : tree_(key_compare_impl()) {
  for (const auto& item : items) {
    tree_.insert_or_increment(item);
  }
}

template <typename Key, typename Compare>
multiset<Key, Compare>::multiset(const multiset& ms) : tree_(ms.tree_) {}

template <typename Key, typename Compare>
multiset<Key, Compare>::multiset(multiset&& ms) noexcept
    : tree_(std::move(ms.tree_)) {}

template <typename Key, typename Compare>
multiset<Key, Compare>& multiset<Key, Compare>::operator=(const multiset& ms) {
  if (this != &ms) {
    tree_ = ms.tree_;
  }
  return *this;
}

template <typename Key, typename Compare>
multiset<Key, Compare>& multiset<Key, Compare>::operator=(
    multiset&& ms) noexcept {
  if (this != &ms) {
    tree_ = std::move(ms.tree_);
  }
  return *this;
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::iterator multiset<Key, Compare>::begin() {
  return tree_.begin();
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::iterator multiset<Key, Compare>::end() {
  return tree_.end();
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::const_iterator multiset<Key, Compare>::begin()
    const {
  return tree_.begin();
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::const_iterator multiset<Key, Compare>::end()
    const {
  return tree_.end();
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::const_iterator multiset<Key, Compare>::cbegin()
    const {
  return tree_.cbegin();
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::const_iterator multiset<Key, Compare>::cend()
    const {
  return tree_.cend();
}

template <typename Key, typename Compare>
bool multiset<Key, Compare>::empty() const {
  return tree_.size() == 0;
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::size_type multiset<Key, Compare>::size()
    const {
  return tree_.size();
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::size_type multiset<Key, Compare>::max_size()
    const {
  return tree_.max_size();
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::iterator multiset<Key, Compare>::insert(
    const value_type& value) {
  auto result = tree_.insert_or_increment(value);
  return result.first;
}

template <typename Key, typename Compare>
void multiset<Key, Compare>::erase(iterator pos) {
  tree_.erase_or_decrement(pos);
}

template <typename Key, typename Compare>
void multiset<Key, Compare>::clear() {
  tree_.clear();
}

template <typename Key, typename Compare>
void multiset<Key, Compare>::swap(multiset& other) {
  tree_.swap(other.tree_);
}

template <typename Key, typename Compare>
void multiset<Key, Compare>::merge(multiset& other) {
  auto it = other.begin();
  while (it != other.end()) {
    auto current_val = *it;
    insert(current_val);
    other.erase(it);
    it = other.begin();
  }
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::iterator multiset<Key, Compare>::find(
    const key_type& key) {
  Node<value_type>* node = tree_.find(key);
  return iterator(node);
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::const_iterator multiset<Key, Compare>::find(
    const key_type& key) const {
  const Node<value_type>* node = tree_.find(key);
  return const_iterator(node);
}

template <typename Key, typename Compare>
bool multiset<Key, Compare>::contains(const key_type& key) const {
  return tree_.contains(key);
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::size_type multiset<Key, Compare>::count(
    const key_type& key) const {
  return tree_.count(key);
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::iterator multiset<Key, Compare>::lower_bound(
    const key_type& key) {
  Node<value_type>* result = nullptr;
  Node<value_type>* current = tree_.get_root();

  while (current) {
    if (!tree_.get_comp()(current->val_, key)) {
      result = current;
      current = current->left_;
    } else {
      current = current->right_;
    }
  }

  return iterator(result);
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::const_iterator
multiset<Key, Compare>::lower_bound(const key_type& key) const {
  const Node<value_type>* result = nullptr;
  const Node<value_type>* current = tree_.get_root();

  while (current) {
    if (!tree_.get_comp()(current->val_, key)) {
      result = current;
      current = current->left_;
    } else {
      current = current->right_;
    }
  }

  return const_iterator(result);
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::iterator multiset<Key, Compare>::upper_bound(
    const key_type& key) {
  Node<value_type>* result = nullptr;
  Node<value_type>* current = tree_.get_root();

  while (current) {
    if (tree_.get_comp()(key, current->val_)) {
      result = current;
      current = current->left_;
    } else {
      current = current->right_;
    }
  }

  return iterator(result);
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::const_iterator
multiset<Key, Compare>::upper_bound(const key_type& key) const {
  const Node<value_type>* result = nullptr;
  const Node<value_type>* current = tree_.get_root();

  while (current) {
    if (tree_.get_comp()(key, current->val_)) {
      result = current;
      current = current->left_;
    } else {
      current = current->right_;
    }
  }

  return const_iterator(result);
}

template <typename Key, typename Compare>
std::pair<typename multiset<Key, Compare>::iterator,
          typename multiset<Key, Compare>::iterator>
multiset<Key, Compare>::equal_range(const key_type& key) {
  return std::make_pair(lower_bound(key), upper_bound(key));
}

template <typename Key, typename Compare>
template <typename... Args>
danya::vector<typename multiset<Key, Compare>::iterator>
multiset<Key, Compare>::insert_many(Args&&... args) {
  danya::vector<iterator> results;
  (results.push_back(insert(args)), ...);
  return results;
}

}  // namespace danya

#endif
