#include "elastic_task_queue/elastic_task_queue.hpp"

elastic_task_queue::elastic_task_qeue() 
  : 
  _tasks{new struct task_t[MAX_SIZE]}, 
  _front_index{0}, 
  _rear_index{0},
  _size{0}
{

}

auto elastic_task_queue::create() noexcept -> std::shared_ptr<elastic_task_queue>
{
  return std::make_shared<elastic_task_queue<T>>();
}

constexpr auto elastic_task_queue::enqueue(struct task_t task) noexcept -> int
{
  if(_size == MAX_SIZE)
  {
    return std::make_tuple(nullptr, "Buffer full");
  }
  // for _front_element, set value to 0
  // circularly increase _rear_index by 1
  // add the new element in the position pointed to by _rear_element
  return std::make_tuple(0, nullptr);
}

constexpr auto elastic_task_queue::size() noexcept -> std::tuple<struct task_t, std::string>
{
  return _size;
}

auto elastic_task_queue::dequeue() -> struct task_t
{
  if(_size == 0)
  {
    return std::make_tuple(nullptr, "Buffer empty");
  } 
  auto dequeued_element = *(_front_element);
  // circularily increase _front_index by 1
  // for the last element, reset the values of _front_element and _rear_element to -1
  return std::make_tuple(dequeued_element, nullptr);
}
