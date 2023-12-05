#include "elastic_task_queue/producer.hpp"

auto producer::create() noexcept -> std::unique_ptr<producer>
{
  return std::make_unique<producer>();
}

/**
 * shared_ptr is one of many standard library types where a move construction is cheaper
 * than a copy construction. Copy construction is slower because copying requires the
 * reference counters be incremented atomically whereas moving a shared_ptr doesn't 
 * require touching the reference data or counters. 
 */
//producer::producer(std::shared_ptr<elastic_task_queue> task_queue) 
//  : _task_queue(std::move(task_queue))
//{
//
//}

producer::producer(){}

auto producer::run(const std::stop_source& stop_source) -> void
{
  fmt::print("Starting producer\n");

  std::stop_token token = stop_source.get_token();

  std::stop_callback stop_cb(token, [this]{ terminate(); });

  std::jthread producer([&token]()
  {
    while(!token.stop_requested())
    {
      fmt::print("Producer in thread ID {} is running\n", std::this_thread::get_id());
      std::this_thread::sleep_for(std::chrono::seconds(3));
    }
  });
}

auto producer::terminate() -> void
{
  fmt::print("Terminating producer\n");
}
