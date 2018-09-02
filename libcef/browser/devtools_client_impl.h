// Copyright (c) 2012 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CEF_LIBCEF_BROWSER_DEVTOOLS_CLIENT_IMPL_H_
#define CEF_LIBCEF_BROWSER_DEVTOOLS_CLIENT_IMPL_H_
#pragma once

#include "content/public/browser/devtools_agent_host_client.h"

#include "include/cef_base.h"

class CefDevToolsClient;

class CefDevToolsClientImpl : public virtual content::DevToolsAgentHostClient {
 public:
  CefDevToolsClientImpl(CefRefPtr<CefDevToolsClient> client);

  ~CefDevToolsClientImpl() override;

  void DispatchProtocolMessage(content::DevToolsAgentHost* agent_host,
                               const std::string& message) override;

  void AgentHostClosed(content::DevToolsAgentHost* agent_host) override;

 private:
  CefRefPtr<CefDevToolsClient> client_;
};

#endif  // CEF_LIBCEF_BROWSER_DEVTOOLS_CLIENT_IMPL_H_
