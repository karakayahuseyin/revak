/**
 * @file Router.cc
 * @brief Router class implementation
 * 
 * Copyright (c) 2025 Hüseyin Karakaya (https://github.com/karakayahuseyin)
 * Licensed under the MIT License. Part of the Revak project.
 */

#include "revak/Router.h"
#include "revak/Logger.h"

namespace revak {

bool Router::AddRoute(const std::string& method, const std::string& path, Handler handler) {
  // Basic validation
  if (method.empty() || path.empty() || !handler) {
    Logger::Instance().Log(Logger::Level::ERROR, "Failed to add route: Invalid parameters");
    return false;
  }

  // Simple validation for path
  if (path[0] != '/') {
    Logger::Instance().Log(Logger::Level::ERROR, "Failed to add route: Path must start with '/'");
    return false;
  }

  auto& method_map = routes_[method];

  if (method_map.contains(path)) {
    Logger::Instance().Log(Logger::Level::WARNING, "Route already exists: " + method + " " + path);
    return false;
  }

  method_map[path] = std::move(handler);
  Logger::Instance().Log(Logger::Level::INFO, "Route added: " + method + " " + path);
  return true;
}

Response Router::Dispatch(const Request& request) {
  Logger::Instance().Log(Logger::Level::INFO, "Request received: " + request.Method() + " " + request.Path());
  auto method_it = routes_.find(request.Method());
  if (method_it != routes_.end()) {
    auto path_it = method_it->second.find(request.Path());
    if (path_it != method_it->second.end()) {
      Logger::Instance().Log(Logger::Level::INFO, "Dispatching to handler for: " 
                             + request.Method() + " " + request.Path());
      return path_it->second(request);
    }
  }
  Response response;
  response.SetStatus(404);
  response.SetBody("404 Not Found\n");
  return response;
}

} // namespace revak