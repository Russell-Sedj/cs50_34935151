-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Check all crimes at humphrey street:
-- | 295 | 2021 | 7     | 28  | Humphrey Street |
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time –
-- each of their interview transcripts mentions the bakery.
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 and year = 2021 AND street = 'Humphrey Street';

-- Interviews
-- id = 161, Ruth: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery
-- parking lot and drive away. If you have security footage from the bakery parking lot, you might want to
-- look for cars that left the parking lot in that time frame.
-- id= 162, Eugene: I don't know the thief's name, but it was someone I recognized. Earlier this morning,
-- before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there
-- withdrawing some money.
-- id = 163, Raymond: As the thief was leaving the bakery, they called someone who talked to them for less
-- than a minute. In the call, I heard the thief say that they were planning to take the earliest flight
-- out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase
-- the flight ticket.
SELECT * FROM interviews WHERE day = 28 AND month = 7 AND year = 2021;

-- checks fiftyville airport
-- 8  | CSF | Fiftyville Regional Airport | Fiftyville
SELECT * FROM airports;

-- Check bakery logs at form 10h15 to 10h25
-- 5P2BI95: Vanessa (725) 555-4692 || id 221103
-- 94KL13X: Bruce (367) 555-5533 || id 686048 || bank 49610011 || atm 267, 50 || (375) 555-8161 Robin:864400
-- 6P58WS2: Barry (301) 555-4174 || id 243696 || bank 56171033
-- 4328GD8: Luca (389) 555-5198 || id 467400 || bank 28500762 || atm 246, 48 || Recv:(609) 555-5876 Kathryn:561160 || 6121106406
-- G412CB7: Sofia (130) 555-0289 || id 398010
-- L93JTIZ: Iman (829) 555-5269 || id 396669 || bank 25506511 || atm 288, 20
-- 322W7JE: Diana (770) 555-1861 || id 514354 || bank 26013199 || atm 336, 35 || (725) 555-3243 Philip:847116 || 3391710505
-- 0NTHK55: Kesley (499) 555-9472 || id 560886
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021;

-- 2nd interview:
SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street' AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw';

-- flights id = 36, 29/07/2021 - 8h20 destination = 4|LGA|LaGuardia Airpor|New York City
SELECT * FROM flights WHERE day = 29 AND month = 7 AND year = 2021;

-- check the passengers informations
--| 36        | 5773159633      | 4A   | Bruce (367) 555-5533
SELECT * FROM passengers WHERE flight_id = 36;