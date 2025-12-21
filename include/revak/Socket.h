/**
 * @file Socket.h
 * @brief Socket class declaration
 * 
 * Copyright (c) 2025 Hüseyin Karakaya (https://github.com/karakayahuseyin)
 * Licensed under the MIT License. Part of the Revak project.
 */

#pragma once

#include <cstdint>
#include <sys/socket.h>

namespace revak {

/**
 * @class Socket
 * @brief Represents a TCP socket with basic operations like bind, listen, accept, and close
 */
class Socket {
public:
  /** Constructor to create a new TCP socket (socket() syscall) */
  Socket();

  /** Destructor to close the socket if open (close() syscall) */
  ~Socket();

  // Delete Copy
  Socket(const Socket&) = delete;
  Socket& operator=(const Socket&) = delete;

  // Move Semantics
  Socket(Socket&& other) noexcept;
  Socket& operator=(Socket&& other) noexcept;

  /** Bind the socket to a specific port */
  bool Bind(uint16_t port);

  /** Put the socket into listening mode */
  bool Listen();

  /** Accepts incoming connection and returns new Socket object */
  [[nodiscard]] Socket Accept();

  /** Puts the Socket in non-blocking mode */
  bool SetNonBlocking();

  /** Close the socket */
  bool Close();

  /** 
   * @brief Get the native file descriptor of the socket
   * @return File descriptor as an integer
   */
  [[nodiscard]] int NativeHandle() const { return fd_; }

private:
  /** File descriptor for the socket */
  int fd_{-1};

  /**
   * @brief Wraps an exist file descriptor
   * @param fd File descriptor
   */
  explicit Socket(int fd);
};

} // namespace revak