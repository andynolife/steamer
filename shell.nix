with import <nixpkgs> {};
{
     buildEnv = stdenv.mkDerivation {
       name = "steamer";
       buildInputs = [stdenv ncurses];
     };
}
