Sphere: A redis-like datastore for dataset on sphere

Introduce
=====================

Sphere is a redis-like datastore for dataset on sphere.
It is an implementation of HEALPix from JPL, NASA.

Please refer the article below for details of HEALPix:

 * HEALPix — a Framework for High Resolution Discretization, and Fast Analysis of Data Distributed on the Sphere
 * By K. M. G ́rski et. al.
 * http://arxiv.org/abs/astro-ph/0409513

The project is just at the beginning, and is not ready for use.

Command-line commands
=====================

 * sph cli
 * sph init
 * sph start
 * sph stop
 * sph part

Data types inside Sphere
==========================

We list all accepable types as below:

 * KIND: i.e. pure data, height-based data, time-based data , time-height-based data

 * INDEX: all indexes are 1-based
   * #DIGITS, such as #1234, #5678, for a total ring index
   * DIGITS#DIGITS, such as 123#5678, for the 5678th pixel in the 123th ring
   * @DIGITS, such as @1234, @5678, for a total nested index
   * DIGIT@DIGIT@DIGIT..., such as 3@1@2@3@4, for a nested tree path
   * DIGITS@DIGITS, such as 3@1234, 678@5678, for a nested index inside a particular part

 * ANGULAR: a angular in radius or degree form
   * FLOAT, such as 123.45, for radius-based angular
   * DIGITS:DIGITS:DIGITS such as 359:59:59, for degree-based angular

 * COORD: lng-lat coordinate on sphere
   * ANGULAR ANGULAR

 * KEY: a string

 * HEIGHT: a number

 * TIME:

 * VALUE:

Client commands
=====================

Index query
-----------

 * all
 * ring INDEX
 * rindex INDEX
 * nindex INDEX
 * pindex INDEX
 * path INDEX
 * coord INDEX

Data type query
----------------

 * kind KEY
 * type KEY

Basic
----------------

 * get COORD KEY
 * set COORD KEY VALUE

Height-based data
----------------

 * zget HEIGHT COORD KEY
 * zset HEIGHT COORD KEY VALUE

Time-based data
----------------

 * tget TIME COORD KEY
 * tset TIME COORD KEY VALUE

Time-Height-based data
----------------

 * tzget TIME HEIGHT COORD KEY
 * tzset TIME HEIGHT COORD KEY VALUE

Field operator
----------------

 * grad KEY1 KEY2
 * zgrad HEIGHT KEY1 KEY2
 * tgrad TIME KEY1 KEY2
 * tzgrad TIME HEIGHT KEY1 KEY2

 * rot KEY1 KEY2
 * zrot HEIGHT KEY1 KEY2
 * trot TIME KEY1 KEY2
 * tzrot TIME HEIGHT KEY1 KEY2

 * div KEY1 KEY2
 * zdiv HEIGHT KEY1 KEY2
 * tdiv TIME KEY1 KEY2
 * tzdiv TIME HEIGHT KEY1 KEY2

