private:

    struct ModItem;

    typedef std::vector<ModItem> modVec;

    // Not using iterators because they're invalidated when
    // pushing back/erasing from modItems_ and not using
    // pointers to ModItems because then it's difficult
    // to interact with modItems_
    typedef std::vector<modVec::size_type> indexVec;

    typedef indexVec::iterator indexVecItr;

    typedef indexVec::const_iterator indexVecItr_const;

    /*! A ModItem contains a ModUnit*, its depth value as well as */
    struct ModItem
    {
        ModItem(ModUnit* modUnit, double dpth = 1)
        : mod(modUnit), depth(dpth), baseDepth(dpth)
        { }
        
        /*! The actual ModUnit pointer. */
        ModUnit* mod;
        
        /*! The current modulation depth. */
        double depth;
        
        /*! For sidechaining */
        double baseDepth;
        
        /*! Vector of indices of all masters in modItems_*/
        indexVec masters;
        
        /* Vector of indices of slaves of this ModItem in modItems_ */
        indexVec slaves;
    };

    /*! Indices of all ModItems that are masters for sidechaining
     and thus don't contribute to the ModDocks modulation value */
    indexVec masterItems_;

    /*! Pointer to all ModItems excluding sidechaining masters */
    indexVec nonMasterItems_;

    /*! All ModItems */
    modVec modItems_;

    /*! This is the base value that the modulation happens around */
    double baseValue_;

    /*! Lower boundary value to scale to when modulation trespasses it */
    double lowerBoundary_;

    /*! Higher boundary value to scale to when modulation trespasses it */
    double higherBoundary_;
