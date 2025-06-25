{
  lib, stdenv, fetchFromGitHub,

  cmake,

  opencv
}:

stdenv.mkDerivation rec {
  pname = "hypercine";
  version = "master";

  src = fetchFromGitHub {
    owner = "cadkin";
    repo  = "hypercine";
    rev   = "${version}";
    hash  = "sha256-4JK9A5ap/Dgbp4vNbRTaX+anWk4lK+piphKk6sRPqyI=";
  };

  nativeBuildInputs = [
    cmake
  ];

  buildInputs = [
    opencv
  ];

  cmakeFlags = [
    (lib.cmakeBool "HYPERCINE_USE_DOUBLE_STORAGE" true)
  ];
}

