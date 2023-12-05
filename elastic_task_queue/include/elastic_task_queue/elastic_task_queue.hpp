#pragma once

#ifndef ELASTIC_TASK_QUEUE_HPP
#define ELASTIC_TASK_QUEUE_HPP

#include "elastic_task_queue/elastic_task_queue_export.hpp"
#include <memory>
#include <string>
#include "elastic_task_queue/err.h"

class elastic_task_queue
{
public:
  elastic_task_queue();

  [[nodiscard]]static auto create() noexcept -> std::shared_ptr<elastic_task_queue>;

  constexpr auto enqueue(struct task_t) noexcept -> std::tuple<int, std::string>;

  [[nodiscard]]constexpr auto size() noexcept -> int;

  auto dequeue() -> std::tuple<struct task_t, std::string>;

  
private:

  ELASTIC_TASK_QUEUE_SUPPRESS_C4251
  struct task_t* _tasks;

  ELASTIC_TASK_QUEUE_SUPPRESS_C4251
  unsigned int _front_index;

  ELASTIC_TASK_QUEUE_SUPPRESS_C4251
  struct task_t& _front_element;

  ELASTIC_TASK_QUEUE_SUPPRESS_C4251
  unsigned int _rear_index;

  ELASTIC_TASK_QUEUE_SUPPRESS_C4251
  struct task_t& _rear_element;

  ELASTIC_TASK_QUEUE_SUPPRESS_C4251
  unsigned int _size;

  ELASTIC_TASK_QUEUE_SUPPRESS_C4251
  const unsigned int MAX_SIZE = 100;
};

#endif
