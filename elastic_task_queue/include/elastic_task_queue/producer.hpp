#pragma once

#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <memory>
#include <utility>
#include <stop_token>
#include <thread>
#include <chrono>
#include <fmt/core.h>
#include "elastic_task_queue/elastic_task_queue.hpp"

class producer
{
public:

  [[nodiscard]]static auto create() noexcept -> std::unique_ptr<producer>;
 
  //explicit producer(std::shared_ptr<elastic_task_queue> task_queue);
  producer();

  auto run(const std::stop_source& stop_source) -> void;

  auto terminate() -> void;

private:
  std::shared_ptr<elastic_task_queue> _task_queue;
};

#endif
