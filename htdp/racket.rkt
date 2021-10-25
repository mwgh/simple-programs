;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname racket) (read-case-sensitive #t) (teachpacks ((lib "convert.rkt" "teachpack" "htdp"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "convert.rkt" "teachpack" "htdp")))))
;; HOW DO YOU DESIGN A FUNCTION?
;; contract: (name funct) name : string string -> string
;; purpose: to print the full name of a person whose first name is _first_ and last name is _last_
;; header: write it
;; example: (name "Joe" "Smith") should produce "Joe Smith"
;; write body (most difficult & creative)
(define (name first last)
  (print first last))

;; tests: discover mistakes - check if outputs == predicted
(name "Joe" "Smith")
;; expected value
;;"Joe Smith"