#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "TestClient.h"

void TestClient::event(const openvpn::ClientAPI::Event& aEvent)
{
    if (aEvent.name == "CONNECTED") {
        std::cout << "VPN connected succesfully" << std::endl;
    }
}

void TestClient::log(const openvpn::ClientAPI::LogInfo& aLogInfo)
{
    //std::cout<<aLogInfo.text<<std::endl;
}

void TestClient::external_pki_sign_request(openvpn::ClientAPI::ExternalPKISignRequest& signreq)
{
    signreq.error = true;
    signreq.errorText = "external_pki_sign_request not implemented";
}

void TestClient::external_pki_cert_request(openvpn::ClientAPI::ExternalPKICertRequest& certreq)
{
    if (epki_cert.empty() == false) {
        certreq.cert = epki_cert;
        certreq.supportingChain = epki_ca;
    }
    else {
        certreq.error = true;
        certreq.errorText = "external_pki_cert_request not implemented";
    }
}

bool TestClient::pause_on_connection_timeout()
{
    return false;
}

bool TestClient::ApplyConfigFile(const std::string& aConfigFileName)
{
    std::ifstream lConfigFile;

    lConfigFile.open(aConfigFileName);

    if (lConfigFile.is_open() == false) {
        return false;
    }

    std::string lConfigData{};

    std::stringstream lFileStream;
    lFileStream << lConfigFile.rdbuf();
    lConfigData = lFileStream.str();

    openvpn::ClientAPI::Config lConfig;

    lConfig.content = lConfigData;

    openvpn::ClientAPI::ProvideCreds lCreds;
    lCreds.username = "vpnbook";
    lCreds.password = "cmx6z6n";

    provide_creds(lCreds);

    openvpn::ClientAPI::EvalConfig lEval = eval_config(lConfig);

    return lEval.error == false;
}
