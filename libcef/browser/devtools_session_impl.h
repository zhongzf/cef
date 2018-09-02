// Copyright (c) 2012 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CEF_LIBCEF_BROWSER_DEVTOOLS_SESSION_IMPL_H_
#define CEF_LIBCEF_BROWSER_DEVTOOLS_SESSION_IMPL_H_
#pragma once

#include "base/memory/scoped_refptr.h"

#include "include/cef_devtools.h"

namespace content {
class DevToolsAgentHost;
class DevToolsAgentHostClient;
}  // namespace content

class CefDevToolsSessionImpl : public CefDevToolsSession {
 public:
  CefDevToolsSessionImpl(scoped_refptr<content::DevToolsAgentHost> agent_host,
                         content::DevToolsAgentHostClient* client);
  ~CefDevToolsSessionImpl() override;

  bool Send(const CefString& message) override;
  bool Close() override;

 private:
  scoped_refptr<content::DevToolsAgentHost> agent_host_;
  content::DevToolsAgentHostClient* client_;

  IMPLEMENT_REFCOUNTING(CefDevToolsSessionImpl);
  DISALLOW_COPY_AND_ASSIGN(CefDevToolsSessionImpl);
};

#endif  // CEF_LIBCEF_BROWSER_DEVTOOLS_SESSION_IMPL_H_
