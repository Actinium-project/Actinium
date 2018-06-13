<<<<<<< HEAD
// Copyright (c) 2011-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#define BOOST_TEST_MODULE Actinium Test Suite

#include "net.h"
=======
// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#define BOOST_TEST_MODULE Litecoin Test Suite

#include <net.h>
>>>>>>> upstream/0.16

#include <boost/test/unit_test.hpp>

std::unique_ptr<CConnman> g_connman;

<<<<<<< HEAD
void Shutdown(void* parg)
{
  exit(EXIT_SUCCESS);
}

void StartShutdown()
{
  exit(EXIT_SUCCESS);
=======
[[noreturn]] void Shutdown(void* parg)
{
  std::exit(EXIT_SUCCESS);
}

[[noreturn]] void StartShutdown()
{
  std::exit(EXIT_SUCCESS);
>>>>>>> upstream/0.16
}

bool ShutdownRequested()
{
  return false;
}
