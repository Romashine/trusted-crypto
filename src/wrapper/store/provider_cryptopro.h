#pragma once

#include "../common/common.h"

#include <string.h>

#include "pkistore.h"

class ProviderCryptopro : public Provider{
public:
	ProviderCryptopro();
	~ProviderCryptopro(){};

public:
	Handle<Certificate> static getCert(Handle<std::string> hash, Handle<std::string> category);
	Handle<CRL> static getCRL(Handle<std::string> hash, Handle<std::string> category);

private:
	void init();
	void enumCertificates(HCERTSTORE hCertStore, std::string *category);
	void enumCrls(HCERTSTORE hCertStore, std::string *category);
	Handle<PkiItem> objectToPKIItem(Handle<Certificate> cert);
	Handle<PkiItem> objectToPKIItem(Handle<CRL> crl);

	int static char2int(char input);
	void static hex2bin(const char* src, char* target);
};
