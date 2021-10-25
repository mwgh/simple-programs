;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname metricImperialConv) (read-case-sensitive #t) (teachpacks ((lib "convert.rkt" "teachpack" "htdp"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "convert.rkt" "teachpack" "htdp")) #f)))
;; converts between metric and imperial measurements

(define inchInCm 2.54)
(define feetInInches 12)
(define yardInFeet 3)
(define rodInYards 5.5)
(define furlongInRods 40)
(define mileInFurlongs 8)

(define (cm inches)
  (* inches inchInCm))

(define (inches feet)
  (* feet feetInInches))

(define (feet yards)
  (* yards yardInFeet))

(define (yards rods)
  (* rods rodInYards))

(define (rods furlongs)
  (* furlongs furlongInRods))

(define (furlongs miles)
  (* miles mileInFurlongs))


(define (cmFromFeet feet)
  (cm (inches feet)))

(define (cmFromYards yards)
  (cmFromFeet (feet yards)))

(define (inchesFromRods rods)
  (inches (feet (yards rods))))

(define (feetFromMiles miles)
  (feet (yards (rods (furlongs miles)))))

(cm 1)
(inches 1)
(feet 1)
(yards 1)
(rods 1)
(furlongs 1)

(cmFromFeet 1)
(cmFromYards 1)
(inchesFromRods 1)
(feetFromMiles 1)
