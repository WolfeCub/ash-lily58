{
  description = "Vial QMK firmware dev shell";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-26.05";

  outputs =
    { nixpkgs, ... }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];
      forAllSystems = f: nixpkgs.lib.genAttrs systems (system: f nixpkgs.legacyPackages.${system});
    in
    {
      devShells = forAllSystems (pkgs: {
        default = pkgs.mkShell {
          # qmk propagates the AVR + ARM toolchains, flashing utilities
          # (avrdude, dfu-util, dfu-programmer, ...) and its Python deps.
          packages = [
            pkgs.qmk
            pkgs.picotool
          ];

          shellHook = ''
            export QMK_HOME="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"
          '';
        };
      });

      formatter = forAllSystems (pkgs: pkgs.nixfmt);
    };
}
