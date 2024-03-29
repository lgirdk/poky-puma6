SECTION = "devel"
SUMMARY = "GNU multiprecision arithmetic library"
DESCRIPTION = "GMP is a free library for arbitrary precision arithmetic, operating on signed integers, rational numbers, and floating point numbers"
HOMEPAGE = "http://gmplib.org/"
LICENSE = "GPLv3 LGPLv3"

REVISION = ""

SRC_URI = "https://gmplib.org/download/gmp/gmp-${PV}/gmp-${PV}${REVISION}.tar.bz2 \
	   file://configure.patch \
	   file://amd64.patch "

inherit autotools

ARM_INSTRUCTION_SET = "arm"

acpaths = ""

BBCLASSEXTEND = "native nativesdk"

EXTRA_OECONF += " --enable-cxx=detect"

PACKAGES =+ "libgmpxx"
FILES_libgmpxx = "${libdir}/libgmpxx${SOLIBS}"

SSTATE_SCAN_FILES += "gmp.h"
