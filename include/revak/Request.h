/**
 * @file Request.h
 * @brief Request class declaration
 * 
 * Copyright (c) 2025 Hüseyin Karakaya (https://github.com/karakayahuseyin)
 * Licensed under the MIT License. Part of the Revak project.
 */

#pragma once

#include <string>
#include <string_view>
#include <map>

namespace revak {

/**
 * @class Request
 * @brief Represents an HTTP request with method, path, headers, and body
 */
class Request {
public:
  /** 
   * @brief Construct a Request object from a raw request string
   * @param request Raw HTTP request string
   */
  explicit
  Request(const std::string_view& request);

  /**
   * @brief Get the HTTP method of the request
   * @return HTTP method as a string
   */
  const std::string& Method() const {return method_;}

  /**
   * @brief Get the path of the request
   * @return Request path as a string
   */
  const std::string& Path() const {return path_;}

  /**
   * @brief Get the Body of the request
   * @return Request body as a string
   */
  const std::string& Body() const {return body_;}

private:
  /** HTTP method of the request */
  std::string method_;

  /** Path of the request */
  std::string path_;

  /** Map of header key-value pairs */
  std::map<std::string, std::string> headers_;

  /** Body content of the request */
  std::string body_;
};

} // namespace revak