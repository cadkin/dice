{
  description = "Digital Image Correlation Engine (DICe): a stereo DIC application that runs on Mac, Windows, and Linux";

  inputs = {
    nixpkgs = {
      url = "github:nixos/nixpkgs/25.05";
    };

    parts = {
      url = "github:hercules-ci/flake-parts";
    };
  };

  outputs = inputs @ { self, parts, ... }: (
    parts.lib.mkFlake { inherit inputs; } {
      systems = [
        "x86_64-linux"
        "aarch64-linux"
      ];

      perSystem = { pkgs, ... }: {
        packages = rec {
          hypercine = pkgs.callPackage ./nix/hypercine.nix { };

          dice = pkgs.callPackage ./nix/dice.nix {
            src = self;
            version = "v3.0-beta.8-patch";

            inherit hypercine;
          };

          default = dice;
        };
      };
    }
  );
}
