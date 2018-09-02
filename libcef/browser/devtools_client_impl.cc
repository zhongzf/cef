#include "libcef/browser/devtools_client_impl.h"
#include "include/cef_devtools.h"

CefDevToolsClientImpl::CefDevToolsClientImpl(
    CefRefPtr<CefDevToolsClient> client)
    : client_(client) {}

CefDevToolsClientImpl::~CefDevToolsClientImpl() {}

void CefDevToolsClientImpl::DispatchProtocolMessage(
    content::DevToolsAgentHost* agent_host,
    const std::string& message) {
  // TODO: ensure agent_host always are same
  client_->OnMessage(CefString(message));
}

void CefDevToolsClientImpl::AgentHostClosed(
    content::DevToolsAgentHost* agent_host) {
  client_->OnHostClosed();
}
