# Odometry Holonomic 3 wheels robot
> reference math used <a href="http://modwg.co.uk/wp-content/uploads/2015/06/OmniRoller-Holonomic-Drive-Tutorial.pdf">this</a>

## matrix

  |x| = | a b c | x |s1| <br>
  |y| = | d e f | x |s2| <br>
  |w| = | g h i | x |s3| <br>

## invers
  |s1| = | a b c | x |x| <br>
  |s2| = | d e f | x |y| <br>
  |s3| = | g h i | x |w| <br>
  
 ## motor set
  > m1 = a_inverse* x + b_inverse* y + c_inverse* w; <br>
  > m2 = d_inverse* x + e_inverse* y + f_inverse* w; <br>
  > m3 = g_inverse* x + h_inverse* y + i_inverse* w; <br>

## Author 
> <a href="https://me-danuandrean.github.io/">Danu andrean </a>
