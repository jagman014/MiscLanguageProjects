// string format tokens
(*
    %A any value default layout,
    %b bool,
    %c char,
    %d %i int,
    %e %E float scientific notation,
    %f float,
    %g %G -> either %e or %f which is shorter,
    %M decimal,
    %o octal,
    %O any objects ToString method,
    %s string,
    %x lower hexadecimal,
    %X upper hexadecimal
*)

// can add a numeric value to specifiy width
// then combined with below for extra modification
(*
    0 pads extra spaces with zeros
    - left justifies within space
    + prepends plus if positive number
    (space) prepends space if positive number
*)
