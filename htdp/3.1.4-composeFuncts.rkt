;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname def-functions) (read-case-sensitive #t) (teachpacks ((lib "convert.rkt" "teachpack" "htdp"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "convert.rkt" "teachpack" "htdp")) #f)))
;; how to write a program
;; write down basic materials, calc several examples (test cases), write the bodies
(define costPerAttendee 1.50)
(define baseAttendees 120)
(define baseTicketPrice 5.00)
(define incInAttendees 15)
(define decInPrice 0.1)

;; profit: number -> number
;; to compute the profit as the dif btwn rev and costs
;; at some given ticket-price
(define (profit ticket-price)
  (- (revenue ticket-price)
     (cost ticket-price)))

;; revenue: number -> number
;; to compute the rev, given ticket price
(define (revenue ticket-price)
  (* (attendees ticket-price) ticket-price))

;; cost: number -> number
;; to compute the costs, given ticket-price
(define (cost ticket-price)
  (* costPerAttendee (attendees ticket-price)))

;; attendees: number -> number
;; to compute # of attendees, given ticket-price
(define (attendees ticket-price)
  (+ baseAttendees
     (*(/ incInAttendees decInPrice) (- baseTicketPrice ticket-price))))

(profit 3)
(revenue 3)
(profit 4)
(revenue 4)
(profit 5)
(revenue 5)
