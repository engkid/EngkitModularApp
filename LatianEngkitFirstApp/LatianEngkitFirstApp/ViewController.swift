//
//  ViewController.swift
//  LatianEngkitFirstApp
//
//  Created by Engkit Satia Riswara on 12/02/19.
//  Copyright © 2019 Engkit Satia Riswara. All rights reserved.
//

import UIKit
import MyLocalFramework

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.engkitBiodata()
        self.engkitObjectFunc()
        
    }
    
}

private extension ViewController {
    
    private func engkitBiodata() {
        
        let engkitModel: EngkitModel = EngkitModel.shared
        
        engkitModel.engkitBio()
        
    }
    
    private func engkitObjectFunc() {
        
        let engkitObject: EngkitObject = EngkitObject()
        
        engkitObject.engkitObjectFunc()
        
    }
    
}

