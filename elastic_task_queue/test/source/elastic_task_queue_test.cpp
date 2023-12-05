#include <string>

#include "elastic_task_queue/elastic_task_queue.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Default constructor for task queue should have initial size = 0")
{
  auto const task_queue = elastic_task_queue<int>::create();
  REQUIRE(task_queue->size() == 0);
}

TEST_CASE("Default constructor for producer")
{
  auto const producer = producer::create<int>();

  // TODO: reflection or summat to get private class members
}
