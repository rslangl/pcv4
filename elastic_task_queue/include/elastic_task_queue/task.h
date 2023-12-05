#pragma once

#ifndef TASK_H
#define TASK_H

struct task_t
{
  task_t() : _id{"id"}{};

  char* _id;

  auto print_id() -> char*
  {
    return _id;
  };
  
};

#endif
