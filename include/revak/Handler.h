/**
 * @file Handler.h
 * @brief Handler function type declaration
 * 
 * Copyright (c) 2025 Hüseyin Karakaya (https://github.com/karakayahuseyin)
 * Licensed under the MIT License. Part of the Revak project.
 */

#pragma once

#include <functional>

namespace revak {

class Response;
class Request;

/**
 * @typedef Handler
 * @brief Type definition for request handler functions
 * @code
 * server.Get("/hello", [](const Request& req) {
 *   Response res;
 *   res.SetStatus(200);
 *   res.SetBody("Hello");
 *   return res;
 * });
 * @endcode
 */
using Handler = std::function<Response(const Request&)>;


} // namespace revak