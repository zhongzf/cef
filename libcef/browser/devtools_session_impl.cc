// Copyright (c) 2018 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/public/browser/devtools_agent_host.h"

#include "libcef/browser/devtools_session_impl.h"

CefDevToolsSessionImpl::CefDevToolsSessionImpl(
    scoped_refptr<content::DevToolsAgentHost> agent_host,
    content::DevToolsAgentHostClient* client) :
    agent_host_(std::move(agent_host)),
    client_(client) {
}

CefDevToolsSessionImpl::~CefDevToolsSessionImpl() {
}

bool CefDevToolsSessionImpl::Send(const CefString& message) {
  return agent_host_->DispatchProtocolMessage(client_, message.ToString());
}

bool CefDevToolsSessionImpl::Close() {
  if (agent_host_->DetachClient(client_)) {
    // delete
    return true;
  }
  return false;
}
