#ifndef DANYA_SET_H_
#define DANYA_SET_H_

#include <cstddef>
#include <stdexcept>
#include <utility>

#include "rbtree/rbtree.h"
#include "danya_vector.h"

namespace danya {
/**
 * @class set
 * @brief Класс set - контейнер, содержащий уникальные элементы, отсортированные
 * по возрастанию.
 * @details Реализован на основе красно-черного дерева (RBTree) для быстрого
 * доступа и сортировки.
 * @tparam Key Тип элементов, которые будут храниться в контейнере.
 * @tparam Compare Компаратор для сортировки элементов.
 */
template <typename Key, typename Compare = std::less<Key>>
class set {
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
  /**
   * @typedef key_type
   * @brief Тип ключа, который используется для элементов.
   */
  using key_type = Key;
  /**
   * @typedef value_type
   * @brief Тип значения, которое хранится в контейнере.
   */
  using value_type = Key;
  /**
   * @typedef reference
   * @brief Ссылка на элемент контейнера.
   */
  using reference = value_type&;
  /**
   * @typedef const_reference
   * @brief Константная ссылка на элемент контейнера.
   */
  using const_reference = const value_type&;
  /**
   * @typedef iterator
   * @brief Тип итератора для обхода контейнера.
   */
  using iterator = typename RBTree<value_type, key_compare_impl>::iterator;
  /**
   * @typedef const_iterator
   * @brief Константный тип итератора для обхода контейнера.
   */
  using const_iterator =
      typename RBTree<value_type, key_compare_impl>::const_iterator;
  /**
   * @typedef size_type
   * @brief Тип для хранения размера контейнера.
   */
  using size_type = std::size_t;
  /**
   * @typedef key_compare
   * @brief Компаратор, используемый для сравнения ключей.
   */
  using key_compare = Compare;

  /**
   * @brief Конструктор по умолчанию.
   * @details Создает пустой контейнер.
   */
  explicit set() : tree_(key_compare_impl()) {}

  /**
   * @brief Конструктор со списком инициализации.
   * @details Создает контейнер, инициализированный элементами из
   * `std::initializer_list`.
   * @param items Список инициализации.
   */
  explicit set(std::initializer_list<value_type> const& items);

  /**
   * @brief Конструктор копирования.
   * @details Создает новый контейнер как копию другого.
   * @param s Объект `set` для копирования.
   */
  explicit set(const set& s);

  /**
   * @brief Конструктор перемещения.
   * @details Создает новый контейнер, перемещая ресурсы из другого.
   * @param s Объект `set` для перемещения.
   */
  explicit set(set&& s) noexcept;

  /**
   * @brief Деструктор.
   * @details Освобождает ресурсы, занимаемые контейнером.
   */
  ~set() = default;

  /**
   * @brief Оператор присваивания копированием.
   * @details Присваивает содержимое другого контейнера.
   * @param s Объект `set` для копирования.
   * @return Ссылка на текущий объект.
   */
  set& operator=(const set& s);

  /**
   * @brief Оператор присваивания перемещением.
   * @details Перемещает содержимое из другого контейнера.
   * @param s Объект `set` для перемещения.
   * @return Ссылка на текущий объект.
   */
  set& operator=(set&& s) noexcept;

  /**
   * @brief Возвращает итератор на начало контейнера.
   * @return Итератор, указывающий на первый элемент.
   */
  iterator begin();

  /**
   * @brief Возвращает итератор на конец контейнера.
   * @return Итератор, указывающий на позицию после последнего элемента.
   */
  iterator end();

  /**
   * @brief Возвращает константный итератор на начало контейнера.
   * @return Константный итератор, указывающий на первый элемент.
   */
  const_iterator begin() const;

  /**
   * @brief Возвращает константный итератор на конец контейнера.
   * @return Константный итератор, указывающий на позицию после последнего
   * элемента.
   */
  const_iterator end() const;

  /**
   * @brief Возвращает константный итератор на начало контейнера.
   * @return Константный итератор, указывающий на первый элемент.
   */
  const_iterator cbegin() const;

  /**
   * @brief Возвращает константный итератор на конец контейнера.
   * @return Константный итератор, указывающий на позицию после последнего
   * элемента.
   */
  const_iterator cend() const;

  /**
   * @brief Находит элемент с заданным ключом.
   * @param key Ключ для поиска.
   * @return Итератор, указывающий на найденный элемент, или `end()` если
   * элемент не найден.
   */
  iterator find(const key_type& key);

  /**
   * @brief Находит элемент с заданным ключом (константная версия).
   * @param key Ключ для поиска.
   * @return Константный итератор, указывающий на найденный элемент, или `end()`
   * если элемент не найден.
   */
  const_iterator find(const key_type& key) const;

  /**
   * @brief Проверяет, пуст ли контейнер.
   * @return `true`, если контейнер не содержит элементов, иначе `false`.
   */
  bool empty() const;

  /**
   * @brief Возвращает количество элементов в контейнере.
   * @return Количество элементов.
   */
  size_type size() const;

  /**
   * @brief Возвращает максимально возможное количество элементов, которое может
   * хранить контейнер.
   * @return Максимальный размер.
   */
  size_type max_size() const;

  /**
   * @brief Вставляет элемент в контейнер.
   * @details Если элемент с таким значением уже есть, вставка не происходит.
   * @param value Элемент для вставки.
   * @return Пара: итератор на вставленный или уже существующий элемент и
   * `bool`, указывающий, произошла ли вставка.
   */
  std::pair<iterator, bool> insert(const value_type& value);

  /**
   * @brief Удаляет элемент по позиции итератора.
   * @param pos Итератор, указывающий на элемент для удаления.
   */
  void erase(iterator pos);

  /**
   * @brief Очищает содержимое контейнера.
   * @details Удаляет все элементы, оставляя контейнер пустым.
   */
  void clear();

  /**
   * @brief Обменивает содержимое с другим контейнером.
   * @param other Контейнер для обмена.
   */
  void swap(set& other);

  /**
   * @brief Объединяет содержимое с другим контейнером.
   * @details Перемещает элементы из `other` в текущий контейнер. Элементы, уже
   * существующие в текущем контейнере, не переносятся.
   * @param other Контейнер для объединения.
   */
  void merge(set& other);

  /**
   * @brief Проверяет, содержит ли контейнер элемент с заданным ключом.
   * @param key Ключ для поиска.
   * @return `true`, если элемент найден, иначе `false`.
   */
  bool contains(const key_type& key) const;

  /**
   * @brief Вставляет несколько элементов в контейнер.
   * @tparam Args Типы вставляемых аргументов.
   * @param args Элементы для вставки.
   * @return Вектор пар, где каждая пара содержит итератор на вставленный
   * элемент и флаг успешности вставки.
   */
  template <typename... Args>
  danya::vector<std::pair<iterator, bool>> insert_many(Args&&... args);
};

/**
 * @brief Конструктор со списком инициализации.
 * @details Проходится по списку и вставляет каждый элемент в дерево.
 */
template <typename Key, typename Compare>
set<Key, Compare>::set(std::initializer_list<value_type> const& items) {
  for (const auto& item : items) {
    tree_.insert(item);
  }
}

/**
 * @brief Конструктор копирования.
 * @details Использует конструктор копирования базового дерева.
 */
template <typename Key, typename Compare>
set<Key, Compare>::set(const set& s) : tree_(s.tree_) {}

/**
 * @brief Конструктор перемещения.
 * @details Использует конструктор перемещения базового дерева.
 */
template <typename Key, typename Compare>
set<Key, Compare>::set(set&& s) noexcept : tree_(std::move(s.tree_)) {}

/**
 * @brief Оператор присваивания копированием.
 * @details Копирует дерево из другого объекта.
 */
template <typename Key, typename Compare>
set<Key, Compare>& set<Key, Compare>::operator=(const set& s) {
  if (this != &s) {
    tree_ = s.tree_;
  }
  return *this;
}

/**
 * @brief Оператор присваивания перемещением.
 * @details Перемещает дерево из другого объекта.
 */
template <typename Key, typename Compare>
set<Key, Compare>& set<Key, Compare>::operator=(set&& s) noexcept {
  if (this != &s) {
    tree_ = std::move(s.tree_);
  }
  return *this;
}

/**
 * @brief Возвращает итератор на начало контейнера.
 * @details Возвращает итератор, указывающий на первый элемент в отсортированном
 * порядке.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::iterator set<Key, Compare>::begin() {
  return tree_.begin();
}

/**
 * @brief Возвращает итератор на конец контейнера.
 * @details Возвращает итератор, указывающий на позицию после последнего
 * элемента.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::iterator set<Key, Compare>::end() {
  return tree_.end();
}

/**
 * @brief Возвращает константный итератор на начало контейнера.
 * @details Возвращает итератор, указывающий на первый элемент в отсортированном
 * порядке.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::const_iterator set<Key, Compare>::begin() const {
  return tree_.begin();
}

/**
 * @brief Возвращает константный итератор на конец контейнера.
 * @details Возвращает итератор, указывающий на позицию после последнего
 * элемента.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::const_iterator set<Key, Compare>::end() const {
  return tree_.end();
}

/**
 * @brief Возвращает константный итератор на начало контейнера.
 * @details Возвращает итератор, указывающий на первый элемент в отсортированном
 * порядке.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::const_iterator set<Key, Compare>::cbegin() const {
  return tree_.cbegin();
}

/**
 * @brief Возвращает константный итератор на конец контейнера.
 * @details Возвращает итератор, указывающий на позицию после последнего
 * элемента.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::const_iterator set<Key, Compare>::cend() const {
  return tree_.cend();
}

/**
 * @brief Проверяет, пуст ли контейнер.
 * @details Возвращает `true`, если контейнер не содержит элементов.
 */
template <typename Key, typename Compare>
bool set<Key, Compare>::empty() const {
  return tree_.size() == 0;
}

/**
 * @brief Возвращает количество элементов в контейнере.
 * @details Возвращает количество элементов, хранящихся в дереве.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::size_type set<Key, Compare>::size() const {
  return tree_.size();
}

/**
 * @brief Возвращает максимально возможное количество элементов.
 * @details Возвращает максимальный размер, который может хранить дерево.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::size_type set<Key, Compare>::max_size() const {
  return tree_.max_size();
}

/**
 * @brief Вставляет элемент в контейнер.
 * @details Использует метод вставки дерева, который гарантирует уникальность
 * элементов.
 */
template <typename Key, typename Compare>
std::pair<typename set<Key, Compare>::iterator, bool> set<Key, Compare>::insert(
    const value_type& value) {
  return tree_.insert(value);
}

/**
 * @brief Удаляет элемент по итератору.
 * @details Использует метод удаления дерева.
 */
template <typename Key, typename Compare>
void set<Key, Compare>::erase(iterator pos) {
  tree_.erase(pos);
}

/**
 * @brief Очищает содержимое.
 * @details Вызывает метод очистки дерева.
 */
template <typename Key, typename Compare>
void set<Key, Compare>::clear() {
  tree_.clear();
}

/**
 * @brief Обменивает содержимое.
 * @details Вызывает метод обмена содержимого дерева.
 */
template <typename Key, typename Compare>
void set<Key, Compare>::swap(set& other) {
  tree_.swap(other.tree_);
}

/**
 * @brief Объединяет два множества.
 * @details Проходит по элементам `other` и пытается вставить их в текущий
 * контейнер. Если вставка успешна, элемент удаляется из `other`.
 */
template <typename Key, typename Compare>
void set<Key, Compare>::merge(set& other) {
  for (auto it = other.begin(); it != other.end();) {
    auto current_it = it++;
    if (insert(*current_it).second) {
      other.erase(current_it);
    }
  }
}

/**
 * @brief Проверяет наличие элемента.
 * @details Использует метод `contains` базового дерева.
 */
template <typename Key, typename Compare>
bool set<Key, Compare>::contains(const key_type& key) const {
  return tree_.contains(key);
}

/**
 * @brief Находит элемент по ключу.
 * @details Возвращает итератор на найденный элемент.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::iterator set<Key, Compare>::find(
    const key_type& key) {
  Node<value_type>* node = tree_.find(key);
  return iterator(node);
}

/**
 * @brief Находит элемент по ключу (константная версия).
 * @details Возвращает константный итератор на найденный элемент.
 */
template <typename Key, typename Compare>
typename set<Key, Compare>::const_iterator set<Key, Compare>::find(
    const key_type& key) const {
  const Node<value_type>* node = tree_.find(key);
  return const_iterator(node);
}

/**
 * @brief Вставляет несколько элементов за один вызов.
 * @details Использует variadic templates и `push_back` для вставки каждого
 * аргумента.
 */
template <typename Key, typename Compare>
template <typename... Args>
danya::vector<std::pair<typename set<Key, Compare>::iterator, bool>>
set<Key, Compare>::insert_many(Args&&... args) {
  danya::vector<std::pair<iterator, bool>> results;
  (results.push_back(insert(args)), ...);
  return results;
}

}  // namespace danya

#endif
