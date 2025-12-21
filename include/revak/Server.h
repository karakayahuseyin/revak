/**
 * @file Server.h
 * @brief Server class declaration
 * 
 * Copyright (c) 2025 Hüseyin Karakaya (https://github.com/karakayahuseyin)
 * Licensed under the MIT License. Part of the Revak project.
 */

#pragma once

#include "Router.h"
#include "Socket.h"
#include "ThreadPool.h"

#include <atomic>

namespace revak {
/**
 * @class Server
 * @brief Represents an HTTP server with routing and multithreading capabilities
 */
class Server {
public:
  /**
   * @brief Create a new Server instance
   * @param port Port number to bind the server
   * @param thread_nums Number of threads in the thread pool (default is 4)
   */
  explicit Server(uint16_t port, size_t thread_nums = 4);

  /** Destructor to stop the server */
  ~Server();

  /**
   * @brief Run the server to accept and handle incoming connections
   */
  void Run();

  /**
   * @brief Stop the server from accepting new connections
   */
  bool Stop();

  /**
   * @brief Add a route to the server's router
   * @param method HTTP method (e.g., "GET", "POST")
   * @param path URL path (e.g., "/home")
   * @param handler Handler function to process the request
   * @return true if the route was added successfully, false otherwise
   */
  bool AddRoute(const std::string& method, const std::string& path, Handler handler);

  /**
   * @brief Shortcut for adding GET route
   * @param path Request path
   * @param handler Handler function for the route
   * @return true if the route was added successfully, false otherwise
   */
  bool Get(const std::string& path, Handler handler);

  /**
   * @brief Shortcut for adding POST route
   * @param path Request path
   * @param handler Handler function for the route
   * @return true if the route was added successfully, false otherwise
   */
  bool Post(const std::string& path, Handler handler);

  /**
   * @brief Shortcut for adding PUT route
   * @param path Request path
   * @param handler Handler function for the route
   * @return true if the route was added successfully, false otherwise
   */
  bool Put(const std::string& path, Handler handler);
  
  /**
   * @brief Shortcut for adding DELETE route
   * @param path Request path
   * @param handler Handler function for the route
   * @return true if the route was added successfully, false otherwise
   */
  bool Delete(const std::string& path, Handler handler);

private:
  /** Port number to bind the server */
  uint16_t port_;

  /** Number of threads in the thread pool */
  size_t thread_nums_;
  
  /** Atomic flag to control server running state */
  std::atomic<bool> running_{false};
  
  /** Socket for handling network connections */
  Socket socket_;

  /** Thread pool for handling requests concurrently */
  ThreadPool thread_pool_;

  /** Router for managing routes and dispatching requests */
  Router router_;
};

} // namespace revak 