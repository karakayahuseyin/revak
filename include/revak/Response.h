/**
 * @file Response.h
 * @brief Response class declaration
 * 
 * Copyright (c) 2025 Hüseyin Karakaya (https://github.com/karakayahuseyin)
 * Licensed under the MIT License. Part of the Revak project.
 */

#pragma once

#include <map>
#include <string>

namespace revak {

/**
 * @class Response
 * @brief Represents a response with status code, headers, and body content
 */
class Response {
public:
  Response() = default;
  ~Response() = default;

  // disable copy
  Response(const Response&) = delete;
  Response& operator=(const Response&) = delete;

  // allow move
  Response(Response&&) = default;
  Response& operator=(Response&&) = default;

  /**
   * @brief Set the status code of the response
   * @param code Status code as an integer
   */
  void SetStatus(int code);

  /**
   * @brief Set a header key-value pair
   * @param key Header key
   * @param value Header value
   */
  void SetHeader(std::string key, std::string value);

  /**
   * @brief Set the body content of the response
   * @param content Body content as a string
   */
  void SetBody(std::string content);

  /**
   * @brief Convert the response to a raw HTTP response string
   * @return Raw HTTP response as a string
   */
  std::string ToString() const;

  /**
   * @brief Get the status code of the response
   * @return Status code as an integer
   */
  int GetStatusCode() const;

  /**
   * @brief Get the status text corresponding to the status code
   * @return Status text as a string
   */
  std::string GetStatusText() const;
  
private:

  /** Status code of the response */
  int status_code_{200};

  /** Map to store header key-value pairs */
  std::map<std::string, std::string> headers_;

  /** Body content of the response */
  std::string body_;
};

} // namespace revak