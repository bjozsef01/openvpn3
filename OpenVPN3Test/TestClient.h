#pragma once

#include <string>
#include <client/ovpncli.hpp>

class TestClient : public openvpn::ClientAPI::OpenVPNClient
{
public:
    virtual void event(const openvpn::ClientAPI::Event& aEvent) override;

    virtual void log(const openvpn::ClientAPI::LogInfo& aLogInfo) override;

    virtual void external_pki_sign_request(openvpn::ClientAPI::ExternalPKISignRequest& signreq) override;

    virtual void external_pki_cert_request(openvpn::ClientAPI::ExternalPKICertRequest& certreq) override;

    virtual bool pause_on_connection_timeout() override;

public:
    bool ApplyConfigFile(const std::string& aConfigFileName);

private:
    std::string epki_ca;
    std::string epki_cert;
};