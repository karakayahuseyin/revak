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

/** Handler function type */
using Handler = std::function<Response(const Request&)>;
/**
 * @code
 * server.Get("/hello", [](const Request& req) {
 *   Response res;
 *   res.SetStatus(200);
 *   res.SetBody("Hello");
 *   return res;
 * });
 * @endcode
 */

} // namespace revak