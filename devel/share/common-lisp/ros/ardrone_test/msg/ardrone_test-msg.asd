
(cl:in-package :asdf)

(defsystem "ardrone_test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Drone_odo" :depends-on ("_package_Drone_odo"))
    (:file "_package_Drone_odo" :depends-on ("_package"))
    (:file "est_co" :depends-on ("_package_est_co"))
    (:file "_package_est_co" :depends-on ("_package"))
  ))