{
  src, version,

  lib, stdenv,

  cmake,

  openmpi, trilinos-mpi, opencv, hypercine, lapack, blas
}:

stdenv.mkDerivation rec {
  pname = "dice";
  inherit version src;

  nativeBuildInputs = [
    cmake
  ];

  buildInputs = [
    openmpi
    trilinos-mpi
    opencv
    hypercine
    lapack
    blas
  ];

  cmakeFlags = [
    (lib.cmakeBool "DICE_DOWNLOAD_HYPERCINE" false)
    "-Wno-dev"
  ];
}

