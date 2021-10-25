;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 3.3.2-4-volume-area) (read-case-sensitive #t) (teachpacks ((lib "convert.rkt" "teachpack" "htdp"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "convert.rkt" "teachpack" "htdp")) #f)))
(define (area-of-disk r)
  (* pi r r))

(define (circumference-of-disk r)
  (* 2 pi r))

;; contract: volume-cylinder: number number -> number
;; purpose: to compute the volume of a cylinder, given its radius and height
;; example: (volume-cylinder 1 3) should produce 3pi
(define (volume-cylinder r height)
  (* (area-of-disk r) height))

;; area-cylinder: number number -> number
;; to compute area of cylinder, given radius and height
(define (area-cylinder r height)
  (+ (* 2 (area-of-disk r)) (* height (circumference-of-disk r))))

(define (area-pipe r length)
  (* length (circumference-of-disk r)))

(volume-cylinder 1 3)
(area-cylinder 1 3)
(area-pipe 1 3)

;; u = h/t
(define (height g t)
  (* 1/2 (speed g t) t))

(define (speed g t)
  (* g t))

(height 1 4)

(define (fahrenheitToCelsius f)
 (- (* (+ f 40) 5/9) 40))

(define (celsiusToFahrenheit c)
  (- (* (+ c 40) 9/5) 40))

(fahrenheitToCelsius 32)
(celsiusToFahrenheit 0)

;; inverse returns f
(define (I f)
  (celsiusToFahrenheit (fahrenheitToCelsius f)))

(I 32)
