# openvpn3

Preprocessor definitions: 

_CRT_SECURE_NO_WARNINGS
NOMINMAX
_WIN32_WINNT=0x0600
USE_ASIO
ASIO_STANDALONE
USE_OPENSSL
TAP_WIN_COMPONENT_ID=tap0901

Additional dependencies:

ssleay32.lib
libeay32.lib
fwpuclnt.lib
ws2_32.lib
crypt32.lib
iphlpapi.lib
winmm.lib
advapi32.lib
wininet.lib
rpcrt4.lib
Wtsapi32.lib
setupapi.lib

C++ Options:

SDL checks: No
Multi-Byte Character Set
Conformance mode: No
Add command line option: /bigobj